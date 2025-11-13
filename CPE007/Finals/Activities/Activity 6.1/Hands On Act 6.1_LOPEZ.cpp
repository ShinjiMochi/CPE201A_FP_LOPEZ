#include <iostream>

using namespace std;

void ArithmeticComputation (int a, int b);
void TemperatureConvertion (int a);
void CashConvertion (int a);

int main (){
	int int1, int2, x, n;
	
	
	while (true) {
     
        cout << "Choose what calculator to use (1-3) " << endl;
        cout << "(-1 to end): ";
        cin >> n;
        cout << endl;
        
        if (n == -1) {
            break;
        }
       
        if (n != -1) {
           
        switch(n) {
       
            case 1:
            	
              cout << "Input first integer: ";
              cin >> int1;
              cout << "Input second integer: ";
              cin >> int2;
				
			  cout << endl;
			  
              ArithmeticComputation(int1, int2);
              
              break;
           
            case 2:
              	
              cout << "Calculate to C* or F* (1-2): ";
              cin >> x;
              cout << endl;
              
              TemperatureConvertion(x);
             
              break;
           
            case 3:
              	
              cout << "Calculate for USD or PHP (1-2): ";
              cin >> x;
              cout << endl;
              
              CashConvertion(x);
              
              break;
           
            default:
              cout << "Error!" << endl;
              cout << endl;
              break;
			}
		}	
	}
	return 0;
}

void ArithmeticComputation(int a, int b)	 {
	int sum = a + b;
    int product = a * b;
    int diff = a - b;
    int quotient = a / b;
    
    cout << "Sum (+): " << sum << endl;
    cout << "Diff (-): " << diff << endl;
    cout << "Product (*): " << product << endl;
    cout << "Quotient (/): " << quotient << endl;
    cout << endl;
	}

void TemperatureConvertion(int a) {
	int tempF, tempC;
	
	if (a < 2) {
		cout << "Enter Temp in Farenheight: ";
		cin >> tempF;
		
		tempC = (tempF - 32.0) * 5.0 / 9.0;
		
		cout << "Temperature in Celcius is: " << tempC << endl;
		cout << endl;
	}
	else {
		cout << "Enter Temp in Celcius: ";
		cin >> tempC;
		
		tempF = (tempC * 1.8) + 32;
		
		cout << "Temperature in Farenheight is: " << tempF << endl;
		cout << endl;
	}
}

void CashConvertion(int a) {
	int usd, php;
	
	if (a < 2) {
		cout << "Enter amount in USD: ";
		cin >> usd;
		
		php = usd * 58.17;
		
		cout << "The amount in PHP is: " << php << endl;
		cout << endl;
	}
	else{
		cout << "Enter amount in PHP: ";
		cin >> php;
		
		usd = php / 58.17;
		
		cout << "The amount in USD is: " << usd << endl;
		cout << endl;
	}
}


