#Script do make para compilar o texto feito no Latex.

TEX = "monografia"

.PHONY: pdflatex prever abrir limpar limpartudo

compilar: pdflatex

limpo: pdflatex limpar
 	
pdflatex: 
	pdflatex ${TEX}
	bibtex ${TEX}
	pdflatex ${TEX}
	pdflatex ${TEX}

ver:
	evince ${TEX}.pdf &
	
limpar:
	-rm *.log *.aux *.lof *.blg *.bbl *.toc *.dvi *.out *.lot *.lsb *.lsg

limpartudo: limpar
	-rm  *.pdf
