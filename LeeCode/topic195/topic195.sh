# Read from the file file.txt and output the tenth line to stdout.
sed -n 10p file.txt    #方法一
awk 'NR==10' file.txt   #方法二