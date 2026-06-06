/*
* DEEPCRAFT Studio 5.12.5418.0+7793ebcc9f383586f202c2d2f6eafbd7ebe6519d
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 06/06/2026 12:25:05 UTC. Any changes will be lost.
* 
* Model ID  21e859a6-b5e9-4ef1-9dc9-35820e62e3ed
* 
* Memory    Size                      Efficiency
* Buffers   1280000 bytes (RAM)       80 %
* State     64208 bytes (RAM)         100 %
* Readonly  44240 bytes (Flash)       100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv1d-medium-balanced-2
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
* Convolution 1D                 [4000,32]       float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,16,32]
* Activation                     [4000,32]       float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [4000,32]       float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,32,32]
* Batch Normalization            [4000,32]       float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [4000,32]       float      dequeue
*    activation = relu
*    trainable = True
* Max pooling 1D                 [2000,32]       float      dequeue
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
*    weight = float[3,32,32]
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
* (ACC) Accuracy 94.762 %
* (F1S) F1 Score 94.791 %
* 
* Name of class                                               unlabeled             east            north             west
* (TP) True Positive or Correct Positive Prediction                  40               49               58               52
* (FN) False Negative or Incorrect Negative Prediction                2                9                0                0
* (FP) False Positive or Incorrect Positive Prediction                9                0                2                0
* (TN) True Negative or Correct Negative Prediction                 159              152              150              158
* (TPR) True Positive Rate or Sensitivity, Recall               95.24 %          84.48 %         100.00 %         100.00 %
* (TNR) True Negative Rate or Specificity, Selectivity          94.64 %         100.00 %          98.68 %         100.00 %
* (PPV) Positive Predictive Value or Precision                  81.63 %         100.00 %          96.67 %         100.00 %
* (NPV) Negative Predictive Value                               98.76 %          94.41 %         100.00 %         100.00 %
* (FNR) False Negative Rate or Miss Rate                         4.76 %          15.52 %           0.00 %           0.00 %
* (FPR) False Positive Rate or Fall-Out                          5.36 %           0.00 %           1.32 %           0.00 %
* (FDR) False Discovery Rate                                    18.37 %           0.00 %           3.33 %           0.00 %
* (FOR) False Omission Rate                                      1.24 %           5.59 %           0.00 %           0.00 %
* (F1S) F1 Score                                                87.91 %          91.59 %          98.31 %         100.00 %
*/


#define IMAI_TEST_AVG_ACC 0.9476190476190476 // Accuracy
#define IMAI_TEST_AVG_F1S 0.947912006679629 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "unlabeled", TP: 40, FN: 2, FP: 9, TN: 159, TPR: 0.9523809523809, TNR: 0.9464285714285, PPV: 0.8163265306122, NPV: 0.9875776397515, FNR: 0.0476190476190, FPR: 0.0535714285714, FDR: 0.1836734693877, FOR: 0.0124223602484, F1S: 0.8791208791208, }, \
 {name: "east", TP: 49, FN: 9, FP: 0, TN: 152, TPR: 0.8448275862068, TNR: 1, PPV: 1, NPV: 0.9440993788819, FNR: 0.1551724137931, FPR: 0, FDR: 0, FOR: 0.0559006211180, F1S: 0.9158878504672, }, \
 {name: "north", TP: 58, FN: 0, FP: 2, TN: 150, TPR: 1, TNR: 0.9868421052631, PPV: 0.9666666666666, NPV: 1, FNR: 0, FPR: 0.0131578947368, FDR: 0.0333333333333, FOR: 0, F1S: 0.9830508474576, }, \
 {name: "west", TP: 52, FN: 0, FP: 0, TN: 158, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 0, FPR: 0, FDR: 0, FOR: 0, F1S: 1, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 98.305 %
* (F1S) F1 Score 98.315 %
* 
* Name of class                                               unlabeled             east            north             west
* (TP) True Positive or Correct Positive Prediction                 116              154              155              155
* (FN) False Negative or Incorrect Negative Prediction                3                3                3                1
* (FP) False Positive or Incorrect Positive Prediction                7                0                2                1
* (TN) True Negative or Correct Negative Prediction                 464              433              430              433
* (TPR) True Positive Rate or Sensitivity, Recall               97.48 %          98.09 %          98.10 %          99.36 %
* (TNR) True Negative Rate or Specificity, Selectivity          98.51 %         100.00 %          99.54 %          99.77 %
* (PPV) Positive Predictive Value or Precision                  94.31 %         100.00 %          98.73 %          99.36 %
* (NPV) Negative Predictive Value                               99.36 %          99.31 %          99.31 %          99.77 %
* (FNR) False Negative Rate or Miss Rate                         2.52 %           1.91 %           1.90 %           0.64 %
* (FPR) False Positive Rate or Fall-Out                          1.49 %           0.00 %           0.46 %           0.23 %
* (FDR) False Discovery Rate                                     5.69 %           0.00 %           1.27 %           0.64 %
* (FOR) False Omission Rate                                      0.64 %           0.69 %           0.69 %           0.23 %
* (F1S) F1 Score                                                95.87 %          99.04 %          98.41 %          99.36 %
*/


#define IMAI_TRAIN_AVG_ACC 0.9830508474576272 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.9831529468928585 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "unlabeled", TP: 116, FN: 3, FP: 7, TN: 464, TPR: 0.9747899159663, TNR: 0.9851380042462, PPV: 0.9430894308943, NPV: 0.9935760171306, FNR: 0.0252100840336, FPR: 0.0148619957537, FDR: 0.0569105691056, FOR: 0.0064239828693, F1S: 0.9586776859504, }, \
 {name: "east", TP: 154, FN: 3, FP: 0, TN: 433, TPR: 0.9808917197452, TNR: 1, PPV: 1, NPV: 0.9931192660550, FNR: 0.0191082802547, FPR: 0, FDR: 0, FOR: 0.0068807339449, F1S: 0.9903536977491, }, \
 {name: "north", TP: 155, FN: 3, FP: 2, TN: 430, TPR: 0.9810126582278, TNR: 0.9953703703703, PPV: 0.9872611464968, NPV: 0.9930715935334, FNR: 0.0189873417721, FPR: 0.0046296296296, FDR: 0.0127388535031, FOR: 0.0069284064665, F1S: 0.9841269841269, }, \
 {name: "west", TP: 155, FN: 1, FP: 1, TN: 433, TPR: 0.9935897435897, TNR: 0.9976958525345, PPV: 0.9935897435897, NPV: 0.9976958525345, FNR: 0.0064102564102, FPR: 0.0023041474654, FDR: 0.0064102564102, FOR: 0.0023041474654, F1S: 0.9935897435897, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 99.548 %
* (F1S) F1 Score 99.547 %
* 
* Name of class                                               unlabeled             east            north             west
* (TP) True Positive or Correct Positive Prediction                  47               52               64               57
* (FN) False Negative or Incorrect Negative Prediction                1                0                0                0
* (FP) False Positive or Incorrect Positive Prediction                0                0                0                1
* (TN) True Negative or Correct Negative Prediction                 173              169              157              163
* (TPR) True Positive Rate or Sensitivity, Recall               97.92 %         100.00 %         100.00 %         100.00 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %         100.00 %         100.00 %          99.39 %
* (PPV) Positive Predictive Value or Precision                 100.00 %         100.00 %         100.00 %          98.28 %
* (NPV) Negative Predictive Value                               99.43 %         100.00 %         100.00 %         100.00 %
* (FNR) False Negative Rate or Miss Rate                         2.08 %           0.00 %           0.00 %           0.00 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           0.00 %           0.00 %           0.61 %
* (FDR) False Discovery Rate                                     0.00 %           0.00 %           0.00 %           1.72 %
* (FOR) False Omission Rate                                      0.57 %           0.00 %           0.00 %           0.00 %
* (F1S) F1 Score                                                98.95 %         100.00 %         100.00 %          99.13 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.995475113122172 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.995470971349286 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "unlabeled", TP: 47, FN: 1, FP: 0, TN: 173, TPR: 0.9791666666666, TNR: 1, PPV: 1, NPV: 0.9942528735632, FNR: 0.0208333333333, FPR: 0, FDR: 0, FOR: 0.0057471264367, F1S: 0.9894736842105, }, \
 {name: "east", TP: 52, FN: 0, FP: 0, TN: 169, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 0, FPR: 0, FDR: 0, FOR: 0, F1S: 1, }, \
 {name: "north", TP: 64, FN: 0, FP: 0, TN: 157, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 0, FPR: 0, FDR: 0, FOR: 0, F1S: 1, }, \
 {name: "west", TP: 57, FN: 0, FP: 1, TN: 163, TPR: 1, TNR: 0.9939024390243, PPV: 0.9827586206896, NPV: 1, FNR: 0, FPR: 0.0060975609756, FDR: 0.0172413793103, FOR: 0, F1S: 0.9913043478260, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_QUEUE

// All symbols in order
#define IMAI_SYMBOL_MAP {"unlabeled", "east", "north", "west"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0xa6, 0x59, 0xe8, 0x21, 0xe9, 0xb5, 0xf1, 0x4e, 0x9d, 0xc9, 0x35, 0x82, 0x0e, 0x62, 0xe3, 0xed}

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
