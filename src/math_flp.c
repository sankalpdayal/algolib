//#define MINDIFF 2.2250738585072014e-308   // smallest positive double
#define MINDIFF 2.25e-308                   // use for convergence check

double sqroot(double square)
{
    double root=square/3, last, diff=1;
    if (square <= 0.0) return 0;
    do {
        last = root;
        root = (root + square / root) / 2;
        diff = root - last;
    } while (diff > MINDIFF || diff < -MINDIFF);
    return root;
}


double cbroot(double cube)
{
    double root=cube/3, last, diff=1;
    if (cube <= 0.0) return 0;
    do {
        last = root;
        root = (2*root + cube / root / root) / 3;
        diff = root - last;
    } while (diff > MINDIFF || diff < -MINDIFF);
    return root;
}
