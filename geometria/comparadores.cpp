bool lt(double a, double b){return a < b - EPS;}
bool gt(double a, double b){return b < a - EPS;}
bool eq(double a, double b){return !lt(a, b) && !gt(a, b);}