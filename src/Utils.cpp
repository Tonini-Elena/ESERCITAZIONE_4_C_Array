#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"
#include <iomanip>

using namespace std;

bool ImportVectors(const string& inputFilePath,
                   double &S,
                   size_t& n,
                   double*& v1,
                   double*& v2) 
{
    ifstream file(inputFilePath); 
    string tmp;
   // unsigned int S;

    if (file.fail())
        return false; 

    // Leggi "S;1000"
    getline(file, tmp, ';'); 
    file >> S;

    // Leggi "n;8"
    getline(file, tmp, ';');
    file >> n;

    // Salta intestazione "w;r"
    getline(file, tmp, ';'); 
    getline(file, tmp);


    v1 = new double[n]; 
	v2 = new double [n];
	
	for(size_t i=0; i<n; i++){
		file >> v1[i];
        std::getline(file, tmp, ';'); 
        file >> v2[i];	
    }
	
    return true;
}

// Calcola la media pesata: ∑(w[i] * r[i])
double weightedAverage(const size_t& n,
                        const double* const v1,
                        const double* const v2)
{
    double result = 0.0;
    for (size_t i = 0; i < n; ++i)
    {
        result += v1[i] * v2[i];
    }
    return result;
}

// Calcola valore finale V = S * (1 + r)
double ReturnRate( double S,const double rate)
{
    return S * (1 + rate);
}

bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double S,
                  const double rate,
                  const double V)
{
    ofstream output(outputFilePath);
    if (output.fail()) {
        cerr << "file open failed" << endl;
        return false;
    }

    output << fixed << setprecision(2) << "S = " << S << ", n = " << n << endl;

    output << "v1 = [ ";
    for (size_t i = 0; i < n; ++i) {
        output << fixed << setprecision(2) << w[i] << " ";
    }
    output << "]" << endl;

    output << "v2 = [ ";
    for (size_t i = 0; i < n; ++i) {
        output << fixed << setprecision(2) << r[i] << " ";
    }
    output << "]" << endl;

    output << fixed << setprecision(4) << "Rate of Return of the portfolio: " << rate << endl;
    output << fixed << setprecision(2) << "V: " << V << endl;

    output.close();
    return true;
}

string ArrayToString(const size_t& n,
                     const double* const& v)
{
    ostringstream toString;
    toString << "[ ";
    for (size_t i = 0; i < n; i++)
        toString << v[i] << " ";
    toString << "]";
    return toString.str();
}