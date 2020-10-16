set terminal png size 800,600 
set output 'out.png'

# Key means label...
#set key inside bottom right
set xlabel 'Matrix size'
set ylabel 'Time (sec)'
set title 'Matrix multiplication speed on Wlofgang Cluster'
plot  "data.txt" using 2:3 title 'Basic' with linespoint,"data.txt" using 2:4 title 'SIMD' with linespoint,"data.txt" using 2:5 title 'omp' with linespoint
