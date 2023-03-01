echo "enter number"
read n 
a=0
b=1
c=0
i=1
while [ $i -le $n ]
do
    echo $a
    c=$(($a+$b))
    a=$b
    b=$c
    i=$(($i+1))
done
