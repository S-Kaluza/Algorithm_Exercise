#Key means label...
set title "Zaleznosc czasu dzialania algorytmu od jego zlozonosci"
set style data linespoints
set style line 1 lt 1 lw 6
set pointsize 1.5
set ylabel 'Czas pracy T(n) w sekundach'
set xlabel 'Rozmiar danych wejsciowych'
set tics nomirror out
set style line 101 lc rgb '#000000' lt 1 lw 1
set border 3 front ls 101
set style line 102 lc rgb '#d6d7d9' lt 0 lw 1
set grid back ls 102
set format x '%g'

fit a*x**2+b*x+c "data.dat" via a,b,c;
plot "data.dat" using 1:2 title 'Dane doswiadczalne' with lines, a*x**2+b*x+c t 'f(x)=n^2'
