set terminal pngcairo enhanced font "arial,12" fontscale 1.2 size 1200, 800 
set output 'results.png'
set boxwidth 0.9 absolute
set style fill solid 1.00 border lt -1
set key fixed right top vertical autotitle
set style histogram clustered gap 2 title textcolor lt -1
set style data histograms
set xtics border in scale 0,0 nomirror rotate by -45 autojustify
set xtics norangelimit 
set ytics 5
set title "Arduino Pro-Mini (16Mhz/5V)\n(V_{in} = 5V / sampling period = 50ms)" 
set yrange [0.00:50.00] noreverse writeback
set ylabel "Current Consumption (in mA)"
set xlabel "Measurement mode"
#set style line 3 lc rgb '#808080' lt 3 lw 2
set grid ytics lc rgb "#808080" dt 1 lw 3
plot 'results.dat' using 2:xtic(1) ti col, '' u 3 ti col, '' u 4 ti col

