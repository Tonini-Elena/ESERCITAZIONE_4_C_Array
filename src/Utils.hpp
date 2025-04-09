#pragma once

#include <string>

using namespace std;

bool ImportVectors(const string& inputFilePath,
                   double& S,
                   size_t& n,
                   double*& v1,
                   double*& v2);

double weightedAverage(const size_t& n,
                        const double* const v1,
                        const double* const v2);

double ReturnRate(double S, double rate);

bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  const double* const& v1,
                  const double* const& v2,
                  const double S,
                  const double rate,
                  const double V);

string ArrayToString(const size_t& n,
                          const double* const& v);
