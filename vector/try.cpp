#include <iostream>


typedef int INTTYPE;

#define M 10 			/*Number of Stages = Log2N */
#define SIZE 1024 		/* SIZE OF FFT */
#define SIZE2 SIZE>>1

unsigned int reverse_bits(unsigned int input)
{
	int i,rev = 0;
	for (i=0;i<M;i++)
	{
		rev = (rev<<1) | (input & 1 );
		input = input >> 1;
	}
    return rev;
}
void bit_reverse(float X_R[SIZE], float X_I[SIZE], float * OUT_R,float * OUT_I){
    using namespace std;
	//Insert your code here
	 unsigned int reversed;
	 unsigned int i;
	 float temp;
     cout << "start reverse..." << endl;
	 for(int i = 0; i < SIZE; i++){
		 reversed = reverse_bits(i);
		 if (i <= reversed ){
			OUT_R[i] = X_R[reversed];
			OUT_R[reversed] = temp;

			OUT_I[i] = X_I[reversed];
			OUT_I[reversed] = X_I[i];
		}
	 }
     cout << "finish reverse..." << endl;
}

int main()
{   
    using namespace std;

    float X_R[SIZE];
    float X_I[SIZE];
    float Stagel_R[SIZE];
    float Stagel_I[SIZE];
    for(int i=0; i<SIZE; i++)	{

		X_R[i] = i;
		X_I[i] = 0.0;
		Stagel_R[i]=i;
		Stagel_I[i]=1;
	}

    bit_reverse(X_R, X_I, Stagel_R, Stagel_I);

    for(int i=0;i<SIZE;i++)
    {
        cout << Stagel_R[i] << " ";
    }
        cout << endl;
    for(int i=0;i<SIZE;i++)
    {
        cout << Stagel_I[i] << " ";
    }
    
    return 0;
}