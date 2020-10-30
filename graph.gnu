set terminal png size 800,600 
set output 'out.png'

# Key means label...
#set key inside bottom right
set xlabel 'Matrix size'
set ylabel 'Time (sec)'
set title 'Matrix multiplication speed on Wlofgang Cluster'
plot  "data.txt" using 2:3 title 'basic' with linespoint,"data.txt" using 2:4 title 'SIMD' with linespoint,"data.txt" using 2:5 title 'OMP' with linespoint,"data.txt" using 2:6 title 'MPI' with linespoint
