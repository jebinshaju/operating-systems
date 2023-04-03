echo "Simple  calculator"
op=1
while [ $op -ne 5 ]
do
	echo "1 - add , 2 - substract , 3 - multiply , 4 - division , 5 - exit"
	echo "Enter your option"
	read op

	case $op in
		1) echo "Enter 2 numbers to add:"
		read a b
		c=$((a+b))
		echo "SUM : $c"
		;;
		
		2) echo "Enter 2 numbers to substract:"
		read a b
		c=$((a-b))
		echo "diiference : $c"
		;;
		
		3) echo "Enter 2 numbers to multiply:"
		read a b
		c=$((a*b))
		echo "product: $c"
		;;
		
		4) echo "Enter 2 numbers to divide:"
		read a b
		c=$((a/b))
		echo "qoutient : $c"
		;;

	esac
done
