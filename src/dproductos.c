
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>


gsl_complex fexpuni(int n);

gsl_complex fexpuni2(int n);
gsl_complex fexpuni3(int n);

/**
 * 
 * @param n
 * @return 
 */
gsl_complex fexpuni(int n){
    int m=0;
    int k=0;
    
    gsl_complex caux,cexpo;
    
    GSL_SET_COMPLEX(&caux, 1, 0);
    
    for(m=0;m<=n-1;m++){
        for(k=0;k<=n-1;k++){
            GSL_SET_COMPLEX(&cexpo, 0, -2.00*M_PI*k*m/n);
            cexpo=gsl_complex_add_real(gsl_complex_exp (cexpo),1.00);
            caux=gsl_complex_mul(caux,cexpo);
        }
    }
    
    
    return caux;
    
}

/**
 * 
 * @param n
 * @return 
 */
gsl_complex fexpuni2(int n){
    int m=0;
    int k=0;
    
    double daux=1.00;
    
    gsl_complex caux,cexpo;
    
    GSL_SET_COMPLEX(&caux, pow(2,pow(n,2)),0);
    
    GSL_SET_COMPLEX(&cexpo, 0,-1.00*M_PI*n*(n-1)*(n-1)/4.00);
    cexpo=gsl_complex_exp (cexpo);
    caux=gsl_complex_mul(caux,cexpo);
    
    for(m=0;m<=n-1;m++){
        for(k=0;k<=n-1;k++){
            daux*=cos(M_PI*m*k/n);
        }
    }
    
    caux=gsl_complex_mul_real(caux,daux);
    return caux;
}

/**
 * 
 * @param n
 * @return 
 */
gsl_complex fexpuni3(int n){
     int m=0;
  
    
    double daux=1.00;
    
    gsl_complex caux,cexpo;
    
    GSL_SET_COMPLEX(&caux, pow(2,pow(n,2)),0);
    
    GSL_SET_COMPLEX(&cexpo, 0,-1.00*M_PI*n*(n-1)*(n-1)/4.00);
    cexpo=gsl_complex_exp (cexpo);
    caux=gsl_complex_mul(caux,cexpo);
    
    for(m=0;m<=n-1;m++){
        
            daux*=cos(M_PI*m*(n-1)/2.00);
        
    }
    
    caux=gsl_complex_mul_real(caux,daux);
    caux=gsl_complex_mul_real(caux,1.00/pow(2,pow(n-1,2)));
    return caux;
}

