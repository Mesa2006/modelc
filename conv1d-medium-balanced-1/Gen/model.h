/*
* DEEPCRAFT Studio 5.12.5418.0+7793ebcc9f383586f202c2d2f6eafbd7ebe6519d
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 06/06/2026 12:36:15 UTC. Any changes will be lost.
* 
* Model ID  908fa704-b924-4c8c-8f20-01eaba7a56aa
* 
* Memory    Size                      Efficiency
* Buffers   640000 bytes (RAM)        80 %
* State     64208 bytes (RAM)         100 %
* Readonly  25744 bytes (Flash)       100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv1d-medium-balanced-1
* 
* Class Index | Symbol Label
* 0           | unlabeled
* 1           | east
* 2           | north
* 3           | west
* 
* Layer                          Shape           Type       Function
* Sliding Window (data points)   [8000,2]        float      dequeue
*    window_shape = [8000,2]
*    stride = 4000
*    buffer_multiplier = 1
* Input Layer                    [8000,2]        float      dequeue
*    shape = [8000,2]
* Convolution 1D                 [4000,16]       float      dequeue
*    filters = 16
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 2
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,2,16]
* Batch Normalization            [4000,16]       float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[16]
*    beta = float[16]
*    mean = float[16]
*    variance = float[16]
* Activation                     [4000,16]       float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [4000,16]       float      dequeue
*    filters = 16
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,16,16]
* Activation                     [4000,16]       float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [4000,16]       float      dequeue
*    filters = 16
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,16,16]
* Batch Normalization            [4000,16]       float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[16]
*    beta = float[16]
*    mean = float[16]
*    variance = float[16]
* Activation                     [4000,16]       float      dequeue
*    activation = relu
*    trainable = True
* Max pooling 1D                 [2000,16]       float      dequeue
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Convolution 1D                 [2000,32]       float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,16,32]
* Activation                     [2000,32]       float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [2000,32]       float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,32,32]
* Batch Normalization            [2000,32]       float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [2000,32]       float      dequeue
*    activation = relu
*    trainable = True
* Max pooling 1D                 [1000,32]       float      dequeue
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Global average pooling 1D      [32]            float      dequeue
*    trainable = True
* Dense                          [4]             float      dequeue
*    units = 4
*    use_bias = True
*    activation = linear
*    trainable = True
*    weight = float[32,4]
*    bias = float[4]
* Activation                     [4]             float      dequeue
*    activation = softmax
*    trainable = True
* 
* Exported functions:
* 
* int IMAI_dequeue(float *restrict data_out)
*    Description: Dequeue features. RET_SUCCESS (0) on success, RET_NODATA (-1) if no data is available, RET_NOMEM (-2) on internal memory error
*    Parameter data_out is Output of size float[4].
* 
* int IMAI_enqueue(const float *restrict data_in)
*    Description: Enqueue features. Returns SUCCESS (0) on success, else RET_NOMEM (-2) when low on memory.
*    Parameter data_in is Input of size float[2].
* 
* void IMAI_init(void)
*    Description: Initializes buffers to initial state. This function also works as a reset function.
* 
* 
* Disclaimer:
*   The generated code relies on the optimizations done by the C compiler.
*   For example many for-loops of length 1 must be removed by the optimizer.
*   This can only be done if the functions are inlined and simplified.
*   Check disassembly if unsure.
*   tl;dr Compile using gcc with -O3 or -Ofast
*/

#ifndef _IMAI_MODEL_H_
#define _IMAI_MODEL_H_
#ifdef _MSC_VER
#pragma once
#endif

#include <stdint.h>

typedef struct {    
    char *name;
    double TP; // True Positive or Correct Positive Prediction
    double FN; // False Negative or Incorrect Negative Prediction
    double FP; // False Positive or Incorrect Positive Prediction
    double TN; // True Negative or Correct Negative Prediction
    double TPR; // True Positive Rate or Sensitivity, Recall
    double TNR; // True Negative Rate or Specificity, Selectivity
    double PPV; // Positive Predictive Value or Precision
    double NPV; // Negative Predictive Value
    double FNR; // False Negative Rate or Miss Rate
    double FPR; // False Positive Rate or Fall-Out
    double FDR; // False Discovery Rate
    double FOR; // False Omission Rate
    double F1S; // F1 Score
} IMAI_stats;

/*
* Tensorflow Test Set
* 
* (ACC) Accuracy 86.190 %
* (F1S) F1 Score 86.217 %
* 
* Name of class                                               unlabeled             east            north             west
* (TP) True Positive or Correct Positive Prediction                  40               38               53               50
* (FN) False Negative or Incorrect Negative Prediction                2               20                5                2
* (FP) False Positive or Incorrect Positive Prediction               21                0                4                4
* (TN) True Negative or Correct Negative Prediction                 147              152              148              154
* (TPR) True Positive Rate or Sensitivity, Recall               95.24 %          65.52 %          91.38 %          96.15 %
* (TNR) True Negative Rate or Specificity, Selectivity          87.50 %         100.00 %          97.37 %          97.47 %
* (PPV) Positive Predictive Value or Precision                  65.57 %         100.00 %          92.98 %          92.59 %
* (NPV) Negative Predictive Value                               98.66 %          88.37 %          96.73 %          98.72 %
* (FNR) False Negative Rate or Miss Rate                         4.76 %          34.48 %           8.62 %           3.85 %
* (FPR) False Positive Rate or Fall-Out                         12.50 %           0.00 %           2.63 %           2.53 %
* (FDR) False Discovery Rate                                    34.43 %           0.00 %           7.02 %           7.41 %
* (FOR) False Omission Rate                                      1.34 %          11.63 %           3.27 %           1.28 %
* (F1S) F1 Score                                                77.67 %          79.17 %          92.17 %          94.34 %
*/


#define IMAI_TEST_AVG_ACC 0.861904761904762 // Accuracy
#define IMAI_TEST_AVG_F1S 0.8621690439465234 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "unlabeled", TP: 40, FN: 2, FP: 21, TN: 147, TPR: 0.9523809523809, TNR: 0.875, PPV: 0.6557377049180, NPV: 0.9865771812080, FNR: 0.0476190476190, FPR: 0.125, FDR: 0.3442622950819, FOR: 0.0134228187919, F1S: 0.7766990291262, }, \
 {name: "east", TP: 38, FN: 20, FP: 0, TN: 152, TPR: 0.6551724137931, TNR: 1, PPV: 1, NPV: 0.8837209302325, FNR: 0.3448275862068, FPR: 0, FDR: 0, FOR: 0.1162790697674, F1S: 0.7916666666666, }, \
 {name: "north", TP: 53, FN: 5, FP: 4, TN: 148, TPR: 0.9137931034482, TNR: 0.9736842105263, PPV: 0.9298245614035, NPV: 0.9673202614379, FNR: 0.0862068965517, FPR: 0.0263157894736, FDR: 0.0701754385964, FOR: 0.0326797385620, F1S: 0.9217391304347, }, \
 {name: "west", TP: 50, FN: 2, FP: 4, TN: 154, TPR: 0.9615384615384, TNR: 0.9746835443037, PPV: 0.9259259259259, NPV: 0.9871794871794, FNR: 0.0384615384615, FPR: 0.0253164556962, FDR: 0.0740740740740, FOR: 0.0128205128205, F1S: 0.9433962264150, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 97.797 %
* (F1S) F1 Score 97.838 %
* 
* Name of class                                               unlabeled             east            north             west
* (TP) True Positive or Correct Positive Prediction                 119              152              154              152
* (FN) False Negative or Incorrect Negative Prediction                0                5                4                4
* (FP) False Positive or Incorrect Positive Prediction               13                0                0                0
* (TN) True Negative or Correct Negative Prediction                 458              433              432              434
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          96.82 %          97.47 %          97.44 %
* (TNR) True Negative Rate or Specificity, Selectivity          97.24 %         100.00 %         100.00 %         100.00 %
* (PPV) Positive Predictive Value or Precision                  90.15 %         100.00 %         100.00 %         100.00 %
* (NPV) Negative Predictive Value                              100.00 %          98.86 %          99.08 %          99.09 %
* (FNR) False Negative Rate or Miss Rate                         0.00 %           3.18 %           2.53 %           2.56 %
* (FPR) False Positive Rate or Fall-Out                          2.76 %           0.00 %           0.00 %           0.00 %
* (FDR) False Discovery Rate                                     9.85 %           0.00 %           0.00 %           0.00 %
* (FOR) False Omission Rate                                      0.00 %           1.14 %           0.92 %           0.91 %
* (F1S) F1 Score                                                94.82 %          98.38 %          98.72 %          98.70 %
*/


#define IMAI_TRAIN_AVG_ACC 0.9779661016949153 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.978380652983738 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "unlabeled", TP: 119, FN: 0, FP: 13, TN: 458, TPR: 1, TNR: 0.9723991507430, PPV: 0.9015151515151, NPV: 1, FNR: 0, FPR: 0.0276008492569, FDR: 0.0984848484848, FOR: 0, F1S: 0.9482071713147, }, \
 {name: "east", TP: 152, FN: 5, FP: 0, TN: 433, TPR: 0.9681528662420, TNR: 1, PPV: 1, NPV: 0.9885844748858, FNR: 0.0318471337579, FPR: 0, FDR: 0, FOR: 0.0114155251141, F1S: 0.9838187702265, }, \
 {name: "north", TP: 154, FN: 4, FP: 0, TN: 432, TPR: 0.9746835443037, TNR: 1, PPV: 1, NPV: 0.9908256880733, FNR: 0.0253164556962, FPR: 0, FDR: 0, FOR: 0.0091743119266, F1S: 0.9871794871794, }, \
 {name: "west", TP: 152, FN: 4, FP: 0, TN: 434, TPR: 0.9743589743589, TNR: 1, PPV: 1, NPV: 0.9908675799086, FNR: 0.0256410256410, FPR: 0, FDR: 0, FOR: 0.0091324200913, F1S: 0.9870129870129, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 99.095 %
* (F1S) F1 Score 99.095 %
* 
* Name of class                                               unlabeled             east            north             west
* (TP) True Positive or Correct Positive Prediction                  47               52               63               57
* (FN) False Negative or Incorrect Negative Prediction                1                0                1                0
* (FP) False Positive or Incorrect Positive Prediction                1                0                0                1
* (TN) True Negative or Correct Negative Prediction                 172              169              157              163
* (TPR) True Positive Rate or Sensitivity, Recall               97.92 %         100.00 %          98.44 %         100.00 %
* (TNR) True Negative Rate or Specificity, Selectivity          99.42 %         100.00 %         100.00 %          99.39 %
* (PPV) Positive Predictive Value or Precision                  97.92 %         100.00 %         100.00 %          98.28 %
* (NPV) Negative Predictive Value                               99.42 %         100.00 %          99.37 %         100.00 %
* (FNR) False Negative Rate or Miss Rate                         2.08 %           0.00 %           1.56 %           0.00 %
* (FPR) False Positive Rate or Fall-Out                          0.58 %           0.00 %           0.00 %           0.61 %
* (FDR) False Discovery Rate                                     2.08 %           0.00 %           0.00 %           1.72 %
* (FOR) False Omission Rate                                      0.58 %           0.00 %           0.63 %           0.00 %
* (F1S) F1 Score                                                97.92 %         100.00 %          99.21 %          99.13 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.9909502262443439 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.9909520851502848 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "unlabeled", TP: 47, FN: 1, FP: 1, TN: 172, TPR: 0.9791666666666, TNR: 0.9942196531791, PPV: 0.9791666666666, NPV: 0.9942196531791, FNR: 0.0208333333333, FPR: 0.0057803468208, FDR: 0.0208333333333, FOR: 0.0057803468208, F1S: 0.9791666666666, }, \
 {name: "east", TP: 52, FN: 0, FP: 0, TN: 169, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 0, FPR: 0, FDR: 0, FOR: 0, F1S: 1, }, \
 {name: "north", TP: 63, FN: 1, FP: 0, TN: 157, TPR: 0.984375, TNR: 1, PPV: 1, NPV: 0.9936708860759, FNR: 0.015625, FPR: 0, FDR: 0, FOR: 0.0063291139240, F1S: 0.9921259842519, }, \
 {name: "west", TP: 57, FN: 0, FP: 1, TN: 163, TPR: 1, TNR: 0.9939024390243, PPV: 0.9827586206896, NPV: 1, FNR: 0, FPR: 0.0060975609756, FDR: 0.0172413793103, FOR: 0, F1S: 0.9913043478260, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_QUEUE

// All symbols in order
#define IMAI_SYMBOL_MAP {"unlabeled", "east", "north", "west"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0x04, 0xa7, 0x8f, 0x90, 0x24, 0xb9, 0x8c, 0x4c, 0x8f, 0x20, 0x01, 0xea, 0xba, 0x7a, 0x56, 0xaa}

// First nibble is bit encoding, second nibble is number of bytes
#define IMAGINET_TYPES_NONE	(0x0)
#define IMAGINET_TYPES_FLOAT32	(0x14)
#define IMAGINET_TYPES_FLOAT64	(0x18)
#define IMAGINET_TYPES_INT8	(0x21)
#define IMAGINET_TYPES_INT16	(0x22)
#define IMAGINET_TYPES_INT32	(0x24)
#define IMAGINET_TYPES_INT64	(0x28)
#define IMAGINET_TYPES_QDYN8	(0x31)
#define IMAGINET_TYPES_QDYN16	(0x32)
#define IMAGINET_TYPES_QDYN32	(0x34)

// data_in [2] (8 bytes)
#define IMAI_DATA_IN_COUNT (2)
#define IMAI_DATA_IN_TYPE float
#define IMAI_DATA_IN_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_IN_SCALE (1)
#define IMAI_DATA_IN_OFFSET (0)
#define IMAI_DATA_IN_IS_QUANTIZED (0)

// data_out [4] (16 bytes)
#define IMAI_DATA_OUT_COUNT (4)
#define IMAI_DATA_OUT_TYPE float
#define IMAI_DATA_OUT_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_OUT_SCALE (1)
#define IMAI_DATA_OUT_OFFSET (0)
#define IMAI_DATA_OUT_IS_QUANTIZED (0)

#define IMAI_KEY_MAX (41)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
int IMAI_dequeue(float *restrict data_out);
int IMAI_enqueue(const float *restrict data_in);
void IMAI_init(void);

#endif /* _IMAI_MODEL_H_ */
