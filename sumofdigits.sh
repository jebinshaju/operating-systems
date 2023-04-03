echo "Enter a number"
read n
s=0
while [ $n -ne 0 ]
do 
r=$((n % 10))
s=$((s + r))
n=$((n / 10))
done
echo "The sum is $s"
