echo "Enter number of terms"
read n
a=0
b=1
echo $a
echo $b
c=$((a + b))
while [ $n -gt 2 ]
do
	echo "$c"
	
	a=$b
	b=$c
	c=$((a + b))
	n=$((n-1))
	
done
