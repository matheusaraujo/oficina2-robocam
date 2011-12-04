#include <stdio.h>
#include <stdlib.h>
#include <cc3.h>
#include <cc3_ilp.h>
#include <cc3_color_track.h>

#include <cc3_color_info.h>
#include <cc3_frame_diff.h>

const int CENT_X_LEFT = 35;
const int CENT_X_RIGHT = 60;

const int NUM_PIX = 1000;

const char FORWARD = 'a';
const char SPINLEFT = 'b';
const char SPINRIGHT = 'c';
const char BACKWARDS = 'd';
const char STOP = 'e';

void simple_track_color(cc3_track_pkt_t* t_pkt);

int main(void) {
  cc3_track_pkt_t t_pkt;

  uint32_t x0, y0, x1, y1;
  cc3_frame_diff_pkt_t fd_pkt;

  cc3_uart_init (0,
 		 CC3_UART_RATE_9600,
		 CC3_UART_MODE_8N1,
		 CC3_UART_BINMODE_BINARY);

#ifdef VIRTUAL_CAM
  cc3_uart_init (0, 
		 CC3_UART_RATE_115200,
		 CC3_UART_MODE_8N1,
		 CC3_UART_BINMODE_TEXT);
#endif

  setbuf(stdout, NULL);
  setbuf(stdin, NULL);

  cc3_camera_init ();


  //cc3_camera_set_colorspace(CC3_COLORSPACE_YCRCB);
  cc3_camera_set_resolution(CC3_CAMERA_RESOLUTION_LOW);
  cc3_pixbuf_frame_set_subsample(CC3_SUBSAMPLE_NEAREST, 2, 2);
  

  // init pixbuf with width and height
#ifndef VIRTUAL_CAM
  //cc3_pixbuf_load();
#endif
  x0 = 0;
  y0 = 0;
  x1 = cc3_g_pixbuf_frame.raw_width;
  y1 = cc3_g_pixbuf_frame.raw_height;

  fd_pkt.coi = 1;
  fd_pkt.template_width = 8;
  fd_pkt.template_height = 8;
  t_pkt.track_invert = false;

  // Load in your tracking parameters
  t_pkt.lower_bound.channel[CC3_CHANNEL_RED] = 80;
  t_pkt.upper_bound.channel[CC3_CHANNEL_RED] = 170;
  t_pkt.lower_bound.channel[CC3_CHANNEL_GREEN] = 25;
  t_pkt.upper_bound.channel[CC3_CHANNEL_GREEN] = 70;
  t_pkt.lower_bound.channel[CC3_CHANNEL_BLUE] = 0;
  t_pkt.upper_bound.channel[CC3_CHANNEL_BLUE] = 35; 
  t_pkt.noise_filter = 0;

  cc3_pixbuf_frame_set_roi (x0, y0, x1, y1);

  int i = 0;
  
  while(true) {
    simple_track_color(&t_pkt);
#ifdef VIRTUAL_CAM
	printf( "Scanning IMG%05d.PPM: \n", i++);
    printf( "centroid = %d,%d bounding box = %d,%d,%d,%d num pix= %d density = %d\n",
		    t_pkt.centroid_x, t_pkt.centroid_y,
		    t_pkt.x0, t_pkt.y0, t_pkt.x1, t_pkt.y1,
		    t_pkt.num_pixels, t_pkt.int_density );
#endif

#ifndef VIRTUAL_CAM
	if(t_pkt.centroid_x < CENT_X_LEFT) {
		printf("%c", SPINRIGHT);
	}
	else if(t_pkt.centroid_x > CENT_X_RIGHT) {
		printf("%c", SPINLEFT);
	}
	else if(t_pkt.num_pixels < NUM_PIX) {
		printf("%c", FORWARD);
	}
	else {
		printf("%c", STOP);
	}
#endif
   }
  
}


void simple_track_color(cc3_track_pkt_t * t_pkt)
{
  cc3_image_t img;

  img.channels = 3;
  img.width = cc3_g_pixbuf_frame.width;
  img.height = 1;               // image will hold just 1 row for scanline processing
  img.pix = cc3_malloc_rows (1); 
  if (img.pix == NULL) {
    return;
  }

    cc3_pixbuf_load ();
    if (cc3_track_color_scanline_start (t_pkt) != 0) {
      while (cc3_pixbuf_read_rows (img.pix, 1)) {
	   // This does the HSV conversion 
	   // cc3_rgb2hsv_row(img.pix,img.width);
           cc3_track_color_scanline (&img, t_pkt);
          }
        }
    cc3_track_color_scanline_finish (t_pkt);

  free (img.pix);
  return;
}
