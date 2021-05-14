#include <iostream>


class TransformerStyleNeuralNetwork {
    public:
        float forward(float input);
        void backward();

        void set_weights(float new_weights);
        void set_bias(float new_bias);

    private:
        float weights;
        float bias;
};


float TransformerStyleNeuralNetwork::forward(float input) {
    return weights * input + bias;
}

void TransformerStyleNeuralNetwork::backward() {
    weights = 0.0f;
    bias = 0.0f;
}

void TransformerStyleNeuralNetwork::set_weights(float new_weights) {
    weights = new_weights;
}

void TransformerStyleNeuralNetwork::set_bias(float new_bias) {
    bias = new_bias;
}


using TSNN = TransformerStyleNeuralNetwork;


int main() {
    TSNN t;
}

