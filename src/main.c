/* 
 * File:   main.c
 * Author: alfonso
 *
 * Created on 17 de noviembre de 2013, 12:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>



extern gsl_complex fexpuni(int n);

extern gsl_complex fexpuni2(int n);

extern gsl_complex fexpuni3(int n);
/*
 * 
 */
int main(int argc, char** argv) {
    int n=3;
    
    gsl_complex caux;
    
    for(n=3;n<=10;n+=2){
        caux=gsl_complex_sub(fexpuni(n),fexpuni2(n));
        
        printf("1:2 %d %lf %lf\n",n,GSL_REAL(caux),GSL_IMAG(caux));
        
        caux=gsl_complex_sub(fexpuni(n),fexpuni3(n));
        
        printf("1:3 %d %lf %lf\n",n,GSL_REAL(caux),GSL_IMAG(caux));
    }
    
    
    return (EXIT_SUCCESS);
}

