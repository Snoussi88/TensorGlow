#include<vector>
#include<iostream>
#include <random>
#include <math.h>





double quad_error(std::vector<std::vector<double>> &data, std::vector<double> &data_y, std::vector<double> &weights){
    double sum = 0;
    int samples = data.size();
    for (int i =0; i < weights.size(); i++){
        double output = 0;
        for (int j=0; j<data[i].size(); j++){
            output = output + (data[i][j]*weights[j]);
        }
        sum = sum + pow((output-data_y[i]),2.0);
    }
    return sum/samples;
}


void read_weights(std::vector<double> &weights) {
    for(int i=0; i<weights.size()-1;i++){
        std::cout << "weights vector is:" << weights[i] << std::endl;
    }
}










void percepetron(std::vector<std::vector<double>> &data, std::vector<double> &data_y){
    
    //pushing 1's on every single observation, to take in consideration the threshold weight.
    for(int i =0; i<data.size();i++){
        data[i].push_back(1);
    }
    

    //randomizing the first initialization of the weights vector.
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0,1.0);

    /* initializing the weights vector for the first time.*/
    std::vector<double> weights;
    for (int i = 0; i < data[0].size()-1; i++)
        weights.push_back(distribution(generator));
    
    
    

    while(quad_error(data,data_y,weights)>1){
        
        std::cout <<"error:" << '\t' << quad_error(data,data_y,weights) << '\n';
        read_weights(weights);

        //calculating the perceptron output to find the error. 
        for (int i =0; i < data.size()-1; i++){
            double output = 0;
            for (int j=0; j<data[i].size()-1; j++){
                output = output + (data[i][j]*weights[j]);
            }
            //update the weights.
            double error = (data_y[i]- output);
            for(int k =0; k < weights.size()-1; k++){
                if (error<0){
                    weights[k] = weights[k] + data[i][k];
                } else {
                    weights[k] = weights[k] - data[i][k];
                }      
            }
        }
    }
}



int main() {
    std::vector<std::vector<double>> data = {
        {1,0,0},
        {0,3,0},
        {0,0,2}
    };

    std::vector<double> data_y = {1,3,2};

    percepetron(data,data_y);

    return 0;
}