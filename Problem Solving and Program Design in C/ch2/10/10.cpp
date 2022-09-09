#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	double Px, Py, Qx, Qy; //Point P(Px, Py) and point Q(Qx, Qy)
	double mL, Lconstant; //mL is the slope of L which perpendicular to the line segment PQ.
	//Lconstant is the constant of the equation of the L.

	printf("Enter the point P(x y)> ");
	scanf("%lf %lf", &Px, &Py);
	printf("Enter the point Q(x y)> ");
	scanf("%lf %lf", &Qx, &Qy);
	printf("Point P( %.1lf , %.1lf )\nPoint Q( %.1lf , %.1lf )\n", Px, Py, Qx, Qy);

	mL = -1 / ((Qy - Py) / (Qx - Px)); //mL = -1 / the slope of the line segment PQ

	Lconstant = (Py + Qy) / 2 - (Px + Qx) / 2 * mL; //y = mL * x + Lconstant ==> Lconstant = y - mL * x

	printf("The equation of the perpendicular bisector of the line segment PQ is ==> y = %.1lfx + %.2lf\n", mL, Lconstant);
	//if the line segment PQ is a horizontal line(the slope of PQ is 0), this program won't show the currect answer(inf).
	//We can solve this problem when we learn more program syntax.

	return 0;
}