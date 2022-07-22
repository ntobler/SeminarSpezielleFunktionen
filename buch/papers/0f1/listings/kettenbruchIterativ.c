static double fractionRekursion0f1(const double c, const double x, unsigned int n)
{
    double a = 0.0;
    double b = 0.0;
    double Ak = 0.0;
    double Bk = 0.0;
    double Ak_1 = 0.0;
    double Bk_1 = 0.0;
    double Ak_2 = 0.0;
    double Bk_2 = 0.0;

    for (unsigned int k = 0; k <= n; ++k)
    {
        if (k == 0)
        {
            a = 1.0; //a0
            //recursion fomula for A0, B0
            Ak = a;
            Bk = 1.0;
        }
        else if (k == 1)
        {
            a = 1.0; //a1
            b = x/c; //b1
            //recursion fomula for A1, B1
            Ak = a * Ak_1 + b * 1.0;
            Bk = a * Bk_1;
        }
        else
        {
            a = 1 + (x / (k * ((k - 1) + c)));//ak
            b = -(x / (k * ((k - 1) + c)));   //bk
            //recursion fomula for Ak, Bk
            Ak = a * Ak_1 + b * Ak_2;
            Bk = a * Bk_1 + b * Bk_2;
        }        
        //save old values
        Ak_2 = Ak_1;
        Bk_2 = Bk_1;
        Ak_1 = Ak;
        Bk_1 = Bk; 
    }
    //approximation fraction
    return  Ak/Bk;
}
