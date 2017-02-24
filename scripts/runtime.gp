reset                                                                           
set ylabel 'time(sec)'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:][:0.1]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using 3:xtic(1) with histogram title 'optimized'  , \
'' using 4:xtic(1) with histogram title 'hash'  , \
'' using 5:xtic(1) with histogram title 'bst'  , \
'' using ($0-0.06):($2+0.0035):2 with labels title ' ', \
'' using ($0+0.12):($3+0.0035):3 with labels title ' ', \
'' using ($0+0.24):($4+0.0035):4 with labels title ' ' ,\
'' using ($0+0.36):($5+0.0015):5 with labels title ' ' 

