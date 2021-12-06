/*

Input function 1: x^5 - 5x + 3
Input function 2: e^x cosx - x sin x

The secant method includes utilizing a secant function instead of a tanget to find estimate the root. 

Sir only gave two starting conditions for the secant function. Will use x_0 = -1, x_1 = 10;

*/
#include <stdio.h>
#include <math.h>

float givenFunc0(float);
float givenFunc1(float);
float secant0(float, float);
float secant1(float, float);
float evaluateEa(float, float);

int main(){
    float currentError = 10; // initial condition error
    float initialVal0;
    float initialVal1; 
    float fxStop;
    float errorStop;
    float currentEstimate;
    int choice;
    int stoppingValue = 0;

    printf("This program will evaluate two functions: \n \t\t x^5 - 5x + 3 \n \t\t e^x cosx - x sin x \n");
    printf("Which function to evaluate first? \n [0] x^5 - 5x + 3 \n [1] e^x cosx - x sin x \n >> ");
    scanf("%d", &choice); 

    printf("Iteration stopping condition:");
    scanf("%d", &stoppingValue);

    printf("\n |f(x)| stopping condition: ");
    scanf("%f", &fxStop);

    printf("\n Error stopping condition: ");
    scanf("%f", &errorStop);

    switch(choice){
        case 0: 
            printf("Evaluating x^5 - 5x + 3... \n");
            printf("Initial guess 0: ");
            scanf("%f", &initialVal0);
            printf("Initial guess 1: ");
            scanf("%f", &initialVal1);
            currentEstimate = 0; 
            currentEstimate = secant0(initialVal0, initialVal1); 
            initialVal0 = initialVal1;
            initialVal1 = currentEstimate;
            for(int iterations = 0; iterations <= stoppingValue; iterations++){
                printf("Proceeding with iteration: #%d \n", iterations);
                printf("init_val0 = %0.5f, init_val1 = %0.5f \n", initialVal0, initialVal1);
                currentEstimate = secant0(initialVal0, initialVal1);    
                currentError = evaluateEa(currentEstimate, initialVal0);
                printf("Current estimate: %0.5f \n", currentEstimate);
                if(iterations != 0){
                    printf("Iteration %d has Ea of %f \n", iterations, evaluateEa(currentEstimate, initialVal0));
                    if(currentError <= errorStop || fxStop >= fabs(givenFunc0(currentEstimate))){
                        printf("Iteration reached below error tolerance. Terminating program with following values: \n");
                        printf("\t\t Estimated root: %0.5f \n \t\t |Ea|: %0.5f \n \t\t Iterations: %d \n \t\t |f(x)|: %0.5f \n", currentEstimate, currentError, iterations, fabs(givenFunc0(currentEstimate)));
                    return 0;
                }
                    initialVal0 =  initialVal1;
                    initialVal1 = currentEstimate;
                } 
            } 
            break;
        case 1:
            printf("Evaluating e^x cosx - x sin x... \n");
            printf("Initial guess 0: ");
            scanf("%f", &initialVal0);
            printf("Initial guess 1: ");
            scanf("%f", &initialVal1);
            currentEstimate = 0; 
            currentEstimate = secant1(initialVal0, initialVal1); 
            initialVal0 = initialVal1;
            initialVal1 = currentEstimate;
            for(int iterations = 0; iterations <= stoppingValue; iterations++){
                printf("Proceeding with iteration: #%d \n", iterations);
                printf("init_val0 = %0.5f, init_val1 = %0.5f \n", initialVal0, initialVal1);
                currentEstimate = secant1(initialVal0, initialVal1);    
                currentError = evaluateEa(currentEstimate, initialVal0);
                printf("Current estimate: %0.5f \n", currentEstimate);
                if(iterations != 0){
                    printf("Iteration %d has Ea of %0.5f \n", iterations, evaluateEa(currentEstimate, initialVal0));
                    if(currentError <= errorStop || fxStop >= fabs(givenFunc1(currentEstimate))){
                        printf("Stopping conditions reached. Terminating program with following values: \n");
                        printf("\t\t Estimated root: %0.5f \n \t\t |Ea|: %0.5f \n \t\t Iterations: %d \n \t\t |f(x)|: %0.5f \n", currentEstimate, currentError, iterations, fabs(givenFunc1(currentEstimate)));
                        return 0; 
                }
                    initialVal0 =  initialVal1;
                    initialVal1 = currentEstimate;
                } 
                
            } 
           break;
    }

    return 0;
}

// given func
float givenFunc0(float x){
    return powf(x, 5) - 5*x + 3;
}

float givenFunc1(float x){
    return expf(x)*cosf(x) - x*sinf(x); 
}

// evaluate secant root. Note that xn is current, xp = x_(n-1)
float secant0(float xn,float xp){
    return xn - (givenFunc0(xn)/((givenFunc0(xn) - givenFunc0(xp))/(xn - xp))); 
}

float secant1(float xn,float xp){
    return xn - (givenFunc1(xn)/((givenFunc1(xn) - givenFunc1(xp))/(xn - xp))); 
} 

// evaluates the |Ea| of a given root
float evaluateEa(float current, float previous){
    float num = (current - previous);
    float denom = current;
    float error = fabs(num/denom);
    return error * 100;
}