function q()
{
int d;
d=5;
write d;
}

function p()
{
int c;
read c;
c=c*5;
write c;
call q();
}

function f()
{
int a;
int b;
read a;
if (a==10) b=5; 
else b=2*(a+3);
write b;
}

main()
{
call f();
call p();
}
