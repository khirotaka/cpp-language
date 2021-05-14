#include <iostream>


class TransformerStyleNeuralNetwork {
    public:
        using Tensor = float;
        Tensor forward(Tensor input);
        void backward();

        void set_weights(Tensor new_weights);
        Tensor get_weights();

        void set_bias(Tensor new_bias);
        Tensor get_bias();

    private:
        Tensor weights;
        Tensor bias;
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
TransformerStyleNeuralNetwork::Tensor TransformerStyleNeuralNetwork::get_weights() {
    return weights;
}

TransformerStyleNeuralNetwork::Tensor TransformerStyleNeuralNetwork::get_bias() {
    return bias;
}

void TransformerStyleNeuralNetwork::set_bias(float new_bias) {
    bias = new_bias;
}


using TSNN = TransformerStyleNeuralNetwork;


int main() {
    TSNN t;
}

