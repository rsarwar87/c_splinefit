#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <gsl/gsl_spline.h>
#include <gsl/gsl_interp.h>

void main()
{
  printf("Hellp");

  size_t i;
  const size_t N = 9;

  const double x[] = {7.99, 8.09, 8.19, 8.7, 9.2,
                      10.0, 12.0, 15.0, 20.0};
  const double y[] = {0.0, 2.76429e-5, 4.37498e-2,
                      0.169183, 0.469428, 0.943740,
                      0.998636, 0.999919, 0.999994};

  gsl_interp_accel *acc = gsl_interp_accel_alloc();
  gsl_spline *spline_cubic = gsl_spline_alloc(gsl_interp_cspline, N);
  gsl_spline_init(spline_cubic, x, y, N);
  for (i = 0; i < N; ++i)
    printf("%g %g\n", x[i], y[i]);

  for (i = 0; i <= 100; ++i)
  {
    double xi = (1 - i / 100.0) * x[0] + (i / 100.0) * x[N - 1];
    double yi_cubic = gsl_spline_eval(spline_cubic, xi, acc);

    printf("%g %g \n", xi, yi_cubic);
  }
  gsl_interp_accel_free(acc);
  gsl_spline_free(spline_cubic);
  printf("\n\n");
}