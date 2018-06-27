#include <complex>
#include <iostream>
#include <valarray>

const double PI = 3.141592653589793238460;

typedefstd::complex<double> Complex;
typedefstd::valarray<Complex>CArray;

// Cooley–Tukey FFT (in-place, divide-and-conquer)
voidfft(CArray& x)
{
constsize_t N = x.size();
if (N <= 1) return;

    // divide
CArray even = x[std::slice(0, N/2, 2)];
CArray  odd = x[std::slice(1, N/2, 2)];

    // conquer
fft(even);
fft(odd);

    // combine
for (size_t k = 0; k < N/2; ++k)
    {
        Complex t = std::polar(1.0, -2 * PI * k / N) * odd[k];     //butterfly algorithm to 
x[k    ] = even[k] + t;			   //merge the vector
x[k+N/2] = even[k] - t;
    }
}
 // inverse fft (in-place)

voidifft(CArray& x)
{
    // conjugate the complex numbers
    x = x.apply(std::conj);

    // forward fft
fft( x );

    // conjugate the complex numbers again
    x = x.apply(std::conj);

    // scale the numbers
x /= x.size();

}


int main()
{
const Complex test[];	       /*complex array whose FFT 
		and IFFT are to be calculated*/
int n;
cout<<”enter the array size”;
cin>>n;
cout<<”enter the array elements”;
for(inti=0;i<n;i++)
    {
cin>>test[i];
     }
CArraydata(test, n);			
CArraydata1(test, n);

// forward fft
fft(data);

std::cout<< "fft" <<std::endl;
for (inti = 0; i< n; ++i)
    {
std::cout<< data[i] <<std::endl;              // print the FFT
    }

    // inverse fft
ifft(data1);

std::cout<<std::endl<< "ifft" <<std::endl;
for (inti = 0; i< n; ++i)
    {
std::cout<<data1[i] <<std::endl;             //print the IFFT
    }

return 0;
}
