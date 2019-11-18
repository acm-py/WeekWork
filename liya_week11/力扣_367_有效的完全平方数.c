bool isPerfectSquare(int num)
{
 if (num == 1) 
 {
        return true;
    }
    long tmp = 1;
    while (tmp * tmp < num) {
        tmp++;
    }
    return (tmp * tmp == num);
}
