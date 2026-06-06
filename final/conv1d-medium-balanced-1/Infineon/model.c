/*
* ImagiNet Compiler 5.12.5418.0+7793ebcc9f383586f202c2d2f6eafbd7ebe6519d
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 06/06/2026 15:46:44 UTC. Any changes will be lost.
* 
* Model ID  642766be-f0b0-444f-aa08-b0eabc636a73
* 
* Memory    Size                      Efficiency
* Buffers   192024 bytes (RAM)        100 %
* State     1174264 bytes (RAM)       100 %
* Readonly  31744 bytes (Flash)       100 %
* 
* Exported functions:
* 
*  @description: Try read data from model.
*  @param data_out Output features. Output float[4].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*  int IMAI_dequeue(float *data_out);
* 
*  @description: Try write data to model.
*  @param data_in Input features. Input float[2].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*  int IMAI_enqueue(const float *data_in);
* 
*  @description: Closes and flushes streams, free any heap allocated memory.
*  void IMAI_finalize(void);
* 
*  @description: Resets windows and neural networks(i.e. RNNs) to initial state.
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*  int IMAI_soft_reset(void);
* 
*  @description: Initializes buffers to initial state.
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*  int IMAI_init(void);
* 
* 
* Disclaimer:
*   The generated code relies on the optimizations done by the C compiler.
*   For example many for-loops of length 1 must be removed by the optimizer.
*   This can only be done if the functions are inlined and simplified.
*   Check disassembly if unsure.
*   tl;dr Compile using gcc with -O3 or -Ofast
* 
* Notes:
* 	-> This code was generated with DEEPCRAFT Studio using:
* 		ml-coretools 3.1.0.9404.
* 		tensorflow 2.19.0.
* 	-> This code requires the following Modus Toolbox libraries (add them to your
* 	project using the Library Manager):
* 		ml-middleware 3.2.0.
* 		ml-tflite-micro 3.2.0.
*/

// Global symbol checks
#ifndef COMPONENT_ML_TFLM
	#error Symbol COMPONENT_ML_TFLM is not defined. Visit the Infineon ML\
	deployment example to see how to define this symbol. Add 'COMPONENTS+=ML_TFLM'\
	to your Makefile to enable this symbol.
#endif

#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "cy_retarget_io.h"
#include "cy_utils.h"
#include "mtb_ml_model.h"
#include "mtb_ml_utils.h"
#include "mtb_ml.h"

#include "model.h"

#ifdef __GNUC__
	#define ALIGNED(x) __attribute__((aligned(x)))
#else
	#define ALIGNED(x) __declspec(align(x))
#endif

#if defined(__GNUC__) || defined(__clang__)
	#define ATTRIB_WEAK  __attribute__((weak))
#else
	#define ATTRIB_WEAK 
#endif

#ifdef CY_ML_MODEL_MEM
 #define IM_ML_MODEL_MEM CY_SECTION(EXPAND_AND_STRINGIFY(CY_ML_MODEL_MEM))
#else
 #define IM_ML_MODEL_MEM
#endif

#ifdef CY_ML_ARENA_MEM
 #define IM_ML_ARENA_MEM CY_SECTION(EXPAND_AND_STRINGIFY(CY_ML_ARENA_MEM))
#else
 #define IM_ML_ARENA_MEM CY_SECTION(".cy_socmem_data")
#endif

#ifdef CY_ML_WORKING_MEM
 #define IM_ML_WORKING_MEM CY_SECTION(EXPAND_AND_STRINGIFY(CY_ML_WORKING_MEM))
#else
 #define IM_ML_WORKING_MEM CY_SECTION(".cy_socmem_data")
#endif

// Working memory
static IM_ML_WORKING_MEM ALIGNED(16) int8_t _buffer[192024];
static IM_ML_ARENA_MEM ALIGNED(16) int8_t _state[1174264];

// Parameters
static IM_ML_MODEL_MEM ALIGNED(16) uint32_t _k5[] = {
    0x0000001c, 0x334c4654, 0x00200014, 0x0018001c, 0x00100014, 0x0000000c, 0x00040008, 0x00000014, 
    0x0000001c, 0x00000090, 0x000000e8, 0x000068c0, 0x000068d0, 0x00007b5c, 0x00000003, 0x00000001, 
    0x00000010, 0x000a0000, 0x000c0010, 0x00040008, 0x0000000a, 0x0000000c, 0x0000001c, 0x0000003c, 
    0x0000000f, 0x76726573, 0x5f676e69, 0x61666564, 0x00746c75, 0x00000001, 0x00000004, 0xffffff98, 
    0x00000021, 0x00000004, 0x00000008, 0x6579616c, 0x38315f72, 0x00000000, 0x00000001, 0x00000004, 
    0xffff970a, 0x00000004, 0x00000007, 0x6579616c, 0x00305f72, 0x00000002, 0x00000034, 0x00000004, 
    0xffffffdc, 0x00000024, 0x00000004, 0x00000013, 0x564e4f43, 0x49535245, 0x4d5f4e4f, 0x44415445, 
    0x00415441, 0x000c0008, 0x00040008, 0x00000008, 0x00000023, 0x00000004, 0x00000013, 0x5f6e696d, 
    0x746e7572, 0x5f656d69, 0x73726576, 0x006e6f69, 0x00000025, 0x000067d4, 0x000067cc, 0x0000673c, 
    0x000066ec, 0x0000669c, 0x0000368c, 0x00002a7c, 0x000028ec, 0x000028d0, 0x000028b0, 0x00002890, 
    0x00002870, 0x00001060, 0x00000fd0, 0x000003c0, 0x00000370, 0x00000160, 0x00000140, 0x0000012c, 
    0x0000010c, 0x00000104, 0x000000fc, 0x000000f4, 0x000000ec, 0x000000e4, 0x000000dc, 0x000000d4, 
    0x000000cc, 0x000000c4, 0x000000bc, 0x000000b4, 0x000000ac, 0x000000a4, 0x0000009c, 0x00000094, 
    0x00000074, 0x00000004, 0xffff9812, 0x00000004, 0x00000060, 0x00000010, 0x00000000, 0x000e0008, 
    0x00040008, 0x00000008, 0x00000010, 0x00000024, 0x00060000, 0x00040008, 0x00000006, 0x00000004, 
    0x00000000, 0x0018000c, 0x00100014, 0x0004000c, 0x0000000c, 0x4b4b398a, 0x2817c5ff, 0x00000003, 
    0x00000002, 0x00000004, 0x00000006, 0x39312e32, 0x0000302e, 0xffff987e, 0x00000004, 0x00000010, 
    0x2e362e31, 0x00000030, 0x00000000, 0x00000000, 0xffff86dc, 0xffff86e0, 0xffff86e4, 0xffff86e8, 
    0xffff86ec, 0xffff86f0, 0xffff86f4, 0xffff86f8, 0xffff86fc, 0xffff8700, 0xffff8704, 0xffff8708, 
    0xffff870c, 0xffff8710, 0xffff8714, 0xffff98d6, 0x00000004, 0x00000010, 0x00000001, 0x00000001, 
    0x00003e80, 0x00000002, 0xffff98f2, 0x00000004, 0x00000004, 0x00000001, 0xffff9902, 0x00000004, 
    0x00000010, 0x3e2fe82c, 0x3e0b8ec9, 0xbe4dd59e, 0xbe090bde, 0xffff991e, 0x00000004, 0x00000200, 
    0x3e666d55, 0xbddbba28, 0xbf4ee61e, 0xbdd8cb00, 0x3f6b840e, 0x3ee915bf, 0xbea0245b, 0xbf0b0155, 
    0x3e4f92fd, 0x3f53f856, 0xbf556629, 0x3e056f89, 0x3f13e2fc, 0xbf47f3df, 0x3f3a40a3, 0xbf211ba1, 
    0x3e082d3f, 0x3da65562, 0xbef68563, 0x3f0a59aa, 0xbe4e0cb7, 0x3eb6e8b1, 0x3f2ac082, 0xbf14eb3a, 
    0x3e02374c, 0xbef73e12, 0x3f27719a, 0x3f4e93e0, 0xbf41948c, 0xbf936689, 0xbec7f7ae, 0xbeeae3d3, 
    0x3ea6d7fb, 0xbfc07fc2, 0x3f09667e, 0x3f1b5513, 0x3f45eddf, 0xbe32b253, 0x3eb20f71, 0x3f3096c8, 
    0x3e8d31ec, 0xbf9adffe, 0x3dc70715, 0xc004911c, 0x3ed8548f, 0x3f3bde89, 0xbfe839bc, 0xbf1efb8f, 
    0xbfe3e2bc, 0xbf2410e6, 0xbfb1ff7b, 0xbfed7b1f, 0x3f200c96, 0xbfbc1c2c, 0xbe7470ed, 0xbf991410, 
    0x3ed7c933, 0xbe2c0594, 0x3eb09dbb, 0xbfff11e6, 0xbe6ca9db, 0x3df106ee, 0x3ef412f9, 0xbf81c74e, 
    0xbfaab9fa, 0xbf8addd9, 0x3f1160b8, 0x3f5fc52c, 0xbf9d0fd3, 0x3f21c0aa, 0xbf1cf94d, 0xbf43bfd9, 
    0xbf1a4aac, 0xbfbf87fe, 0x3f6d6f0a, 0x3ef6a4aa, 0xbfefaec6, 0x3efd7998, 0xbfac6089, 0x3eeb2f09, 
    0x3e5b5abb, 0x3f455dfa, 0x3e55ea44, 0xbf931724, 0xbf3868aa, 0x3f18a6c8, 0xbe559095, 0x3e7e2742, 
    0xbfe47918, 0xbf280161, 0x3f284f8a, 0xbefd6c6f, 0x3eba34fb, 0x3f2a2965, 0xbf3554db, 0x3ebabf70, 
    0x3efb15cc, 0x3ed0d44c, 0x3daa9b29, 0xbfdf3830, 0xbfbd9ba2, 0xbfd7ee68, 0x3f1b4e71, 0x3e1883ce, 
    0xbfdad7f4, 0x3e440a28, 0xbea99b98, 0x3f3ca1e5, 0x3e92004a, 0xbe73cd28, 0x3e173520, 0xbf122d53, 
    0x3e99791b, 0xbf2d1aca, 0x3d93c263, 0x3f0abacd, 0x3f04e654, 0x3f02ee4c, 0xbfbe7bc2, 0x3eb92407, 
    0x3e38d09c, 0x3efb7ada, 0xc00e1f93, 0xbe546f7d, 0x3f0d009d, 0x3eb0c666, 0x3ef29ced, 0x3e02a692, 
    0xffff9b2a, 0x00000004, 0x00000040, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0xffff9b76, 0x00000004, 0x00000c00, 0x3e9ca43b, 0xbf4b9220, 
    0xbfa82b70, 0x3ea338d9, 0x3e4f438a, 0xbe31016a, 0x3c975c0a, 0x3c8cfc2c, 0x3d75f4aa, 0xbf36829e, 
    0x3f381efb, 0x3f2cb56a, 0x3ea6a42a, 0xbecab7d2, 0x3ebf5557, 0xbdb2b996, 0xbd874b05, 0xbe17caf7, 
    0x3e722ce7, 0x3e39c824, 0xbbbaa4f2, 0x3cbbe64e, 0x3ddcba7c, 0x3d697c86, 0xbe3ce372, 0xbf169e43, 
    0x3ea29c2c, 0x3d1b618c, 0xbdf462d8, 0xbdc751a7, 0x3cc2c738, 0x3e3e17f8, 0xbf2e80fb, 0xbcf78204, 
    0x3ce73947, 0x3e60b9b4, 0xbe59985b, 0xbe8d6a82, 0x3f13693f, 0x3ede2627, 0xbe6c2bcf, 0xbed072a0, 
    0xbf25bdb5, 0xbf596632, 0xbddbcfc8, 0xbe852780, 0xbe9f8bc3, 0x3e8a4591, 0xbeb1a6c7, 0xbca15169, 
    0x3e25b6c6, 0x3f32e445, 0xbdadd02b, 0x3e0722d6, 0x3ef3ddda, 0x3e8668f4, 0xbe9bf364, 0xbeca992e, 
    0x3e96714c, 0xbd466642, 0x3f407fe0, 0xbd1fdd54, 0x3e8a3872, 0x3e6dd76e, 0xbe84f3cb, 0xbd9bb228, 
    0xbea8549d, 0x3dfca5a0, 0xbee86c7e, 0xbd6d1da3, 0x3db4129c, 0x3e4fc8f7, 0x3e0d3057, 0x3df0ced1, 
    0x3da57522, 0xbb5734ae, 0x3efbbc30, 0x3e546161, 0x3f296772, 0xbded6501, 0xbe17761b, 0xbf7f823c, 
    0xbf6ee963, 0xbe3663e3, 0xbe4a9cb5, 0xbec90225, 0x3e11f060, 0xbe61af77, 0xbe303c70, 0xbdf30239, 
    0xbe3675a5, 0xbeb43399, 0x3c5867f5, 0xbd1bd5e2, 0xbe9e323a, 0x3e7254d1, 0x3ec8f655, 0xbf0ae761, 
    0xbeca8e9e, 0x3dc8c446, 0xbf060a32, 0xbe0a6314, 0x3e7dae94, 0x3d88a785, 0xbed55df0, 0xbed7e248, 
    0x3da318a8, 0xbe843a5f, 0x3c5c791f, 0x3eeee6d9, 0xbea6169c, 0xbdb8f4c8, 0x3e8ac3f9, 0xbea5df3e, 
    0xbcc9351d, 0x3e9c13b3, 0x3da0468a, 0x3e925e10, 0xbd95b656, 0x3da25c5e, 0xbe3d191a, 0xbe4dd43c, 
    0x3d7a7318, 0xbdd2a6c0, 0x3e5fd3c1, 0x3ede0466, 0xbe617468, 0x3e8cc642, 0x3e6345f8, 0xbec2463e, 
    0xbece741f, 0x3e6e68d8, 0xbdcc44a6, 0x3e0f8016, 0x3f07a1d5, 0xbe79ef81, 0xbebc7216, 0x3e644293, 
    0xbec9af1b, 0xbeca51a2, 0x3df7922a, 0x3ebc1adf, 0xbe12c080, 0x3deb77b8, 0x3d428d2b, 0x3e092034, 
    0x3ed56e65, 0x3d4b2788, 0xbe04043f, 0x3d8442f3, 0xbd30a354, 0x3ca787fa, 0xbe2485a0, 0xbe86ee03, 
    0xbefc5016, 0xbecc312a, 0x3ef38488, 0xbd5f0533, 0xbdddd94b, 0x3dd6fd10, 0x3dc65d8d, 0x3eb77182, 
    0x3ceed460, 0x3daf1dc9, 0xbe1aab7b, 0x3e012cac, 0x3ea3c14e, 0x3e1b815c, 0xbee91797, 0xbd86c58c, 
    0xbedcef67, 0xbf238de8, 0x3d8c60e0, 0xbe40a161, 0x3d996eb0, 0x3e144149, 0xbf1af083, 0xbe3aeeb3, 
    0xbe495755, 0xbd919653, 0xbeeafbec, 0xbf0f048b, 0x3ecbf4d7, 0xbd177d51, 0xbe2cc8d1, 0xbebff367, 
    0xbf03f3dd, 0xbf988809, 0x3e79ea99, 0xbee5ad41, 0xbea24d92, 0x3c0cce04, 0x3ea87350, 0xbd1590a6, 
    0x3de46425, 0xbe25190f, 0xbf2b8380, 0x3a072f1a, 0xbf2db213, 0xbf031973, 0xbedc8106, 0xbd09dd20, 
    0xbe366094, 0xbf02e900, 0xbdad0a3f, 0x3e867718, 0xbec527b7, 0xbe6aabfc, 0x3e9f461c, 0xbe9715cf, 
    0xbe03677a, 0x3d0d0ae5, 0xbe6aa575, 0xbdd5058c, 0xbe85c935, 0xbdeb1103, 0xbea8e099, 0x3cd6b4b0, 
    0xbf41c7c3, 0xbe9efeff, 0xbe3644ed, 0xbe217967, 0xbba8a502, 0xbecea522, 0x3e0225c5, 0xbedb303a, 
    0xbd5bc4c6, 0x3e867ee4, 0x3d1e131c, 0xbe856666, 0x3d2b33f7, 0x3c122b9c, 0xbdfbc9a0, 0x3dfc633b, 
    0xbf2d03a1, 0xbeb7dda9, 0xbe86815f, 0x3e004b35, 0xbe423731, 0x3d9fc922, 0xbda1acde, 0x3e50dfea, 
    0xbe9a2402, 0xbeae28da, 0xbe771d26, 0xbefa48a0, 0x3e80f0b8, 0xbed9037d, 0x3ced543c, 0xbf6e00d0, 
    0xbe303b78, 0x3ea81252, 0x3f1f7a52, 0xbf0abc81, 0x3ecb05ab, 0x3e320c3c, 0x3efc74db, 0xbea67dd0, 
    0xbea2a1b2, 0xbef76508, 0x3ea14db8, 0x3cee289f, 0xbed6d71b, 0xbe867a7b, 0xbdb26ee7, 0xbed693e7, 
    0x3e41193b, 0x3e7efc93, 0xbdd58b02, 0x3e56ec81, 0xbd98117c, 0xbd01cd97, 0x3b110b4c, 0xbeed4aec, 
    0xbf06cdd9, 0xbf089c75, 0x3e08c691, 0xbddc6d6d, 0xbe36353e, 0x3ddbfe53, 0x3e5a0649, 0xbe73ac3c, 
    0x3e840473, 0xbd801655, 0xbe499f43, 0xbd6c0625, 0xbf1ed8eb, 0xbef15886, 0x3e72ee56, 0xbfa84028, 
    0xbf0b7165, 0xbe3c925d, 0x3e8354b7, 0xbd81d6e7, 0x3e9d3def, 0xbe181215, 0x3e1c943f, 0x3da3bc1f, 
    0xbf38a9f7, 0xbe434040, 0xbe63d687, 0x3f00e62c, 0xbe1bda9e, 0x3f10689c, 0x3e43197f, 0xbe64823f, 
    0xbf021a69, 0xbeb82356, 0xbe2871be, 0xbec77ae0, 0x3ee95912, 0xbda99fd7, 0xbd89d1e1, 0x3e8e8872, 
    0xbeae4768, 0xbe5b259d, 0x3e09b5ae, 0x3ddf61b4, 0xbe7bb000, 0x3efac588, 0x3e44b7cb, 0x3d968cdc, 
    0x3e8ff998, 0xbd4c0f9f, 0xbef57d17, 0xbcd97507, 0x3eef7dda, 0x3e8db4df, 0x3e9ab7d7, 0xbf09870d, 
    0x3d3fc405, 0xbf07edcd, 0x3e6fc250, 0xbe9b4b84, 0xbdb1518c, 0x3ec68936, 0x3e896281, 0xbe74f5b1, 
    0xbe842493, 0x3e8c39b9, 0xbf43fbe2, 0x3ce725e7, 0x3ead5409, 0x3d303bbb, 0xbf0f6f18, 0xc00090c3, 
    0x3eb97846, 0xbe28b366, 0x3f12dbb9, 0xbf3f170c, 0x3d9231e2, 0xbdb26109, 0x3e29ff04, 0xbeb7be6e, 
    0xbef44053, 0x3dadeb7d, 0xbf0627cd, 0xbdc7f242, 0x3d862e4d, 0xbe2b9d70, 0x3a97d972, 0xbed8644b, 
    0x3e0f6662, 0x3e252c7f, 0x3dd03650, 0xbd7a569d, 0xbe3ef639, 0x3e08cd89, 0x3eeaff12, 0xbe1bc538, 
    0xbeccfbbd, 0xbbd056de, 0x3ebdfa84, 0xbef3cc81, 0xbdf964ec, 0x3e11db75, 0x3e9f4773, 0xbedd9bab, 
    0x3e5c1e36, 0x3ead1bcc, 0xbdf1d395, 0x3e97dc1a, 0x3d69f112, 0xbeab21ac, 0xbe946b46, 0xbe2f0ec9, 
    0x3c926e35, 0x3dbca24c, 0xbd65d5be, 0xbddcda0d, 0x3de7866a, 0x3dcbde2e, 0xbdac3ab5, 0xbf190598, 
    0x3d619004, 0xbee198c1, 0x3e2cbd00, 0xbeced164, 0xbe8a6f08, 0xbebbe015, 0xbe86055c, 0xbf26ffa8, 
    0xbe388dbf, 0x3dcc99e2, 0xbdaec0bc, 0x3cc89209, 0x3dd3fa2e, 0xbe569ed7, 0x3e6f83ec, 0xbe0dc1d0, 
    0xbeebc0a2, 0xbef75259, 0xbca2bf14, 0x3c694df5, 0xbea98745, 0x3e2ee42c, 0xbe6dd9af, 0xbf528b0a, 
    0xbeeecd1a, 0x3e859fb5, 0x3eb6d639, 0xbed6de3e, 0xbdd745fe, 0x3e97ad28, 0x3d9454ea, 0x3c5ba7f6, 
    0xbd0d0f37, 0xbd4bc05f, 0x3e85f901, 0x3bddbadb, 0xbe138c82, 0x3ce5ca07, 0x3e9eb3a3, 0xbe4283e3, 
    0x3de5f3e3, 0xbf51cdae, 0xbf3e1e4d, 0x3e47c7e4, 0x3e3fa173, 0xbedb8001, 0xbeaceeec, 0x3e8a1176, 
    0xbede643f, 0x3cc42977, 0x3e953927, 0x3debd1e6, 0x3e4be3d8, 0x3f07b463, 0x3ee84b05, 0xbf04cd74, 
    0x3c6bb412, 0xbe9e6d01, 0xbf37bcd3, 0x3e41449a, 0x3dcd4b00, 0xbe6424d8, 0xbdaf0768, 0x3ea75ec0, 
    0x3e837842, 0x3ee40617, 0xbde590d4, 0xbca26e88, 0xbe7f74e5, 0x3eddcab7, 0x3dc7e584, 0xbe43ce21, 
    0xbebfd86f, 0x3e58bb84, 0xbe9d2e28, 0xbb329952, 0x3d24ac41, 0x3ee2ac95, 0x3e3c01bf, 0x3ed18e5b, 
    0x3f17977c, 0x3e354de3, 0xbe6c3cac, 0xbe797e25, 0xbd572dac, 0x3ededad8, 0x3d1ce9bf, 0x3f035663, 
    0x3e839c34, 0xbe32f091, 0xbf12538f, 0xbf36165c, 0x3f248a05, 0xbd68c9eb, 0xbf2b46e7, 0xbe8ff902, 
    0xbe52e418, 0x3d6dfaba, 0x3efe0b56, 0xbe4a9ed3, 0xbc2dcdde, 0x3eeda5ed, 0x3e9fa2b8, 0x3e0ee5b1, 
    0x3d51d9a2, 0xbe904eee, 0xbf3cb2c0, 0xbe6b5ce4, 0x3ec9aee8, 0xbe889503, 0xbf5e30cd, 0xbe7df839, 
    0xbede9d00, 0xbed369ff, 0x3e85256b, 0xbe89bbba, 0xbe3e73a2, 0x3ef2e407, 0xbf0803c3, 0xbf354b90, 
    0xbeee7f4b, 0xbeb5c70f, 0xbf5456ab, 0x3dcc4a94, 0x3f1bcfc7, 0x3e65357d, 0xbd9e569a, 0x3ee00944, 
    0xbedde72a, 0xbf2c2275, 0xbdb5741c, 0xbe1b6635, 0xbf429e58, 0x3f25933e, 0x3caa186d, 0xbeeef63a, 
    0xbedd5fda, 0xbf78a178, 0xbf854e09, 0xbd98f1fa, 0x3e0444ac, 0xbf25673e, 0xbf0fc765, 0xbeaa1d7d, 
    0xbe575e1e, 0xbe230580, 0x3e40c1ce, 0xbd508a7e, 0xbe9f2517, 0x3e226c7d, 0x3ebadd74, 0xbef0e5bf, 
    0xbea4c2b5, 0xbf0410bc, 0xbf4993f8, 0xbe321e63, 0xbf09e750, 0xbde3ebb0, 0xbf15492a, 0xbf92617a, 
    0x3d93cc63, 0x3e8b8ac6, 0x3e7aed2e, 0xbd825cbd, 0x3dc250ee, 0xbe9ac3e1, 0x3ed2fc04, 0xbf30d434, 
    0xbf4a4b78, 0xbeb52ccf, 0xbe9809f6, 0xbdcd9cd7, 0xbf126a7f, 0xbe142acf, 0xbe7910f0, 0xbf644b09, 
    0x3ed289ea, 0x3ea069ea, 0xbdd4f1be, 0x3e787bae, 0x3d010a88, 0xbf443c88, 0x3f4fbb1a, 0x3cb05241, 
    0xbcf0877a, 0xbf232a9c, 0x3e49922f, 0x3d623532, 0xbcb8f85f, 0xbe8e9e61, 0x3d8b6e64, 0x3c88a5f7, 
    0x3f4b4311, 0x3ed9dd6e, 0xbed36ab3, 0xbeb3e01a, 0xbed3cee8, 0x3dbe042c, 0xbc35c062, 0xbf0313b2, 
    0xbcf106b3, 0x3bbdff9b, 0xbe8f5ea7, 0xbe262227, 0x3e611860, 0x3d1f8794, 0xbe20b76b, 0xbf1b13ef, 
    0x3eca416b, 0x3bb3179e, 0x3cff1b5f, 0xbf3e3e37, 0xbe194c6c, 0xbc53dc54, 0x3e58b315, 0x3e932b7d, 
    0x3f03e285, 0x3ec0f889, 0xbeb3893c, 0x3cf57155, 0x3e95c290, 0x3e8a16fd, 0xbd07e32e, 0xbfae39ca, 
    0x3ef28458, 0x3c853c2d, 0x3f14fbc6, 0xbf1301f6, 0x3e87ae4d, 0xbe257b89, 0xbb7688e3, 0xbf3b6e85, 
    0xbf1e3f7e, 0xbf3a9cf6, 0xbed3bac4, 0x3e4b1a27, 0xbe195301, 0xbf428930, 0xbc412a50, 0x3eb11e6c, 
    0xbf3ed9f8, 0xbea392f1, 0xbe1b19ee, 0x3e92e8a3, 0xbeb1a96c, 0x3c17728a, 0xbe999bdb, 0xbf09c27d, 
    0xbe841eff, 0xbe8400c3, 0xbef88666, 0x3e14a64e, 0xbe9e84fb, 0xbec7a9a6, 0xbe9b120f, 0x3ec9a256, 
    0xbf4a296b, 0xbe7bbb5c, 0xbe0f2767, 0x3cf8d05f, 0x3cc16efa, 0xbdb5123a, 0xbef6e39c, 0xbf735431, 
    0xbeb17880, 0xbe3d8c6f, 0x3e906c3b, 0x3d4c4e8c, 0xbc806646, 0x3e342c0f, 0xbe2854de, 0x3e130b78, 
    0xbf1be2a1, 0xbeeb2f5f, 0xbf888807, 0x3e7ea6b2, 0xbfba1024, 0x3e8fd917, 0xbf19a352, 0x3e78c759, 
    0x3e2febb2, 0x3e9c3d97, 0xbed0032b, 0xbe89de45, 0x3e65d17d, 0xbc327940, 0xbf32fd01, 0xbeded0b7, 
    0xbeb954dc, 0xbefcff8a, 0x3ef1ebf8, 0xbf3024be, 0x3e133e1e, 0x3de9a226, 0xbf027d60, 0xbe39602d, 
    0x3e2092fc, 0xba86c8fa, 0xbe119c6c, 0xbe83f7d0, 0xbd937f8d, 0x3e33a038, 0xbeea9bfa, 0xbe9d3072, 
    0xbe85914e, 0xbd4dcd19, 0x3e2a7646, 0x3d3700de, 0xbd9a019c, 0xbe2a4147, 0xbf1140f1, 0xbf7166c3, 
    0xbec095a4, 0x3e1eb2db, 0x3e49e71e, 0xbe96232e, 0x3f13aa99, 0x3d3ed3c1, 0xbea5667e, 0x3dcb0f5b, 
    0x3d9b3e55, 0xbd8dd68a, 0x3bb0a381, 0x3d8e8ae7, 0xbe1cdb85, 0x3ec45deb, 0x3ca04551, 0x3d2f64d5, 
    0x3e0d9dd6, 0x3e911c1e, 0xbecca819, 0x3e8d9697, 0x3ddaab97, 0x3e420b62, 0xbf283d43, 0xbe36e9a4, 
    0x3bd8f480, 0x3de1ac03, 0x3e6f1cd3, 0xbfb50285, 0x3e0d8b68, 0x3e079747, 0xbddc8705, 0x3daa6ac3, 
    0xbb7e3b85, 0x3e4c5e8a, 0xbf644ab6, 0x3ded3bab, 0x3e4bb1b4, 0xbe2b86e1, 0xbf19a956, 0x3e31bb22, 
    0x3dd838c7, 0xbe46aa7e, 0x3ea0dcd9, 0xbf1e433b, 0x3e1479c2, 0x3ef35318, 0xbe496997, 0xbe64b3ed, 
    0xbe7a8ade, 0xbd4295e0, 0xbff8c231, 0x3d772e70, 0x3e4cfa4a, 0xbe3c9649, 0xbe8f9682, 0xbf86bc18, 
    0x3e6a3d86, 0x3e0e3dfe, 0x3eca6de7, 0xbfd111d7, 0x3d2093bc, 0x3d417275, 0xffffa782, 0x00000004, 
    0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0xffffa80e, 0x00000004, 0x00001800, 0xbe2b757e, 0x3d8f8672, 0xbe64bd8a, 0x3ed3cc2d, 
    0x3ee4d426, 0x3e3d2f7b, 0x3dfc37ab, 0x3ed94851, 0xbe90710e, 0xbd90ad2d, 0xbe5c9a9c, 0x3e1b59d3, 
    0x3d145e6b, 0x3ebdeed0, 0x3e04976c, 0x3eab6712, 0x3c83202d, 0x3e4c8281, 0x3e177b81, 0x3d482719, 
    0x390fdc10, 0x3dd7a46f, 0xbe494227, 0xbe0ffb1f, 0x3ba278b5, 0xbd43d425, 0x3c090774, 0xbe116948, 
    0x3d306b6f, 0x3ec07159, 0xbe10f15e, 0xbe34f822, 0x3ea7877d, 0xbdca2b4f, 0x3e8e0d72, 0x3e06ec72, 
    0x3e786a17, 0xbe243642, 0x3eaaf37e, 0xbe4719d6, 0xbdf0462a, 0xbd84d24d, 0x3def0ebe, 0x3ea48b22, 
    0xbeb07396, 0xbd8236c0, 0xbc357fa8, 0xbe50ae07, 0xbcf2f7d5, 0xbd77f529, 0x3ed4f403, 0x3d49c946, 
    0xbd1e6da9, 0xbe0d8bfa, 0xbfadf57a, 0xbf26c4fd, 0xbf0c7bb6, 0xbf36dbf0, 0xbda385fc, 0x3d1f1b02, 
    0xbf01f086, 0x3f13ac9d, 0x3eb9178c, 0x3c9e2a2c, 0x3eb7ebcb, 0x3dae7cdf, 0xbe8a1339, 0xbebd766f, 
    0xbf3ff706, 0x3ce2043e, 0xbf1ab074, 0xbfb8aa6c, 0xbe68b6cf, 0x3dee9077, 0xbe3f6e39, 0xbe7efc8c, 
    0xbed5a6b0, 0xbd0122d4, 0xbf1e9665, 0x3aba3259, 0x3e8d11e6, 0x3f518a49, 0xbf810f2e, 0xbe9f9c6e, 
    0x3ee2fd76, 0xbe7adc81, 0xbf71083c, 0xbe1af779, 0xbe3d77c5, 0x3ed7bc2e, 0xbe855fd9, 0x3e024cec, 
    0xbf6c9938, 0xbf2c3bb3, 0xbffa6f80, 0xbe8c6de6, 0xbf124a70, 0xbf6b96b2, 0xbdd61da8, 0xbf2b111c, 
    0xbf8c684e, 0xbdeeed1a, 0xbf03de53, 0xbba463ad, 0x3e9b09a4, 0xbe6762d4, 0x3db59f76, 0xbef65c20, 
    0x3e2007f6, 0xbf35cd4e, 0xbf8792bc, 0xbe42cbc8, 0x3cd3c816, 0xbf470f78, 0x3ee2a5ae, 0xbe8a3cf5, 
    0xbf85f44c, 0xbeb02401, 0x3d6f6d0a, 0x3e2ef825, 0x3e168a56, 0xbe2f3f56, 0x3dedd3ec, 0xbf1c439a, 
    0xbd6b0a7e, 0xbf8d25fd, 0xbe435f14, 0x3e8482d8, 0xbf357005, 0xbf9260f3, 0x3e494567, 0xbe15ea67, 
    0xbf8785e9, 0x3f1a7fcf, 0xbe82b663, 0xbf6d6996, 0xbec55c81, 0xbe5db2a9, 0x3f080057, 0xbf698aba, 
    0x3d215b51, 0xbe89a208, 0x3e45e608, 0x3f432f5d, 0xbd8c2a67, 0xbef6d97e, 0x3e896565, 0x3e8b4ca8, 
    0x3d4494fd, 0x3da315a2, 0x3d5bd033, 0xbe8b3307, 0x3d919899, 0xbf11ff76, 0xbcbcb0ea, 0xbf7392af, 
    0xbc49e29e, 0x3ce11df3, 0x3ece93b3, 0x3ea0b86a, 0xbf4833aa, 0xbe5c1fad, 0x3ea08600, 0x3e7c41ae, 
    0xbe64a624, 0x3e438925, 0xbf156c1f, 0x3e223434, 0xbe0e7119, 0xbe05a95b, 0xbdb8e1a6, 0xbf53c130, 
    0x3d791b59, 0x3e44a13f, 0x3e13f9b0, 0x3e3f140b, 0x3e887c31, 0xbf12864e, 0x3e97cb47, 0x3f2bc483, 
    0x3d340639, 0xbe09fd98, 0xbad8f8b5, 0x3ea9938a, 0xbf2aff17, 0x3eb1d5de, 0x3cb40468, 0xbf1b4d44, 
    0xbf32a8f9, 0x3d312022, 0x3cfe578d, 0x3dc2bb3c, 0xbeadf66b, 0xbdb9e206, 0xbdecc8ab, 0x3db30606, 
    0xbdab9d95, 0x3e5de7ff, 0xbeea33fc, 0xbe8e95e7, 0x3c023cec, 0xbf04535c, 0xbdae28e7, 0xbebe6caa, 
    0x3ed0a72b, 0x3f013760, 0xbf0b09e5, 0xbe21078e, 0xbeb48ca0, 0xbf1335d3, 0x3c5df35f, 0x3f19c06b, 
    0xbf85e4d7, 0x3e0bdf1f, 0x3e89c70e, 0x3e1962b1, 0x3dad2ca1, 0xbeb65482, 0xbc699e4c, 0x3e59c2fe, 
    0xbd7bbff8, 0xbe42fee6, 0xbe7dadf5, 0xbd464976, 0xbe20c822, 0x3e4faf4c, 0x3e830854, 0xbe70ad60, 
    0xbf0ed2be, 0x3f06ebda, 0x3e858295, 0xbf049833, 0xbebf143f, 0xbf383119, 0xbf0761d8, 0xbe92a2af, 
    0x3e4641a8, 0xbed274eb, 0xbf3938ab, 0x3ddc93af, 0xbe6a6b3f, 0x3ea3f730, 0x3e9b22b5, 0xbe94e560, 
    0x3e298dc9, 0x3dfb7549, 0xbea86b6f, 0xbf99c358, 0xbf78d571, 0xbea4e66e, 0xbf5b51fe, 0x3eee90dc, 
    0xbe37d939, 0x3eb56fcc, 0x3eca6234, 0x3e151888, 0x3ee3b864, 0x3f1d8aa6, 0xbdee727a, 0xbe324cbd, 
    0x3e1fb451, 0x3e67dbf5, 0x3e75f607, 0xbf516fb6, 0xbfc5f3b8, 0xbf3c1ca3, 0xbf657462, 0xbe3c2aa5, 
    0xbe13d441, 0x3d55718e, 0x3e3c8b04, 0xbe7fca90, 0x3e576e3e, 0xbe26a580, 0x3e686a20, 0xbe874a35, 
    0xbdd0ba86, 0xbf1242d1, 0x3f06d7e9, 0xbf67937f, 0xbfa159c3, 0xbfaf47eb, 0xbea66a01, 0xbf6cef37, 
    0xbf051ddb, 0x3e9b12a6, 0x3eb6357f, 0xbdbaaf38, 0x3ecb491b, 0x3d3c676e, 0x3e8da1c9, 0x3ee80073, 
    0x3e0ebbca, 0xbe979d0d, 0xbdf9c173, 0x3e319ccd, 0xbda6b8ec, 0xbdd37f08, 0xbe642854, 0xbe59fb8f, 
    0xbe52cc99, 0xbe131d31, 0x3ec588d4, 0x3e44fccf, 0xbe7b9090, 0x3de5db42, 0xbd43c47a, 0x3c03fe41, 
    0x3e9fe0b8, 0x3eb884b8, 0xbf43b910, 0xbf092d42, 0xbe90d3ca, 0xbe859c26, 0xbe9826fc, 0xbf157c8b, 
    0x3ca0fe8f, 0x3e96000c, 0xbd554fa2, 0x3ec47fd8, 0x3e638ee2, 0x3e9a2f12, 0xbe4d9080, 0xbdbcdceb, 
    0xbbc9b763, 0x3e29979f, 0xbf613fea, 0x3bc2b27b, 0xbf3529c6, 0x3e589dbc, 0xbe186ab1, 0x3e454b59, 
    0xbe149084, 0xbd98edbd, 0xbfa80b1b, 0xbed53011, 0xbe8bf8cd, 0xbe62cd83, 0xbd80024e, 0x3e39f5f8, 
    0xbe82cfca, 0xbe68beb7, 0xbe132ff2, 0xbd233765, 0xbd75cd8c, 0xbe4ebf59, 0xbe87c4a3, 0xbe608d43, 
    0xbe83672e, 0xbc8be074, 0xbe3917ac, 0xbe32c211, 0xbe8bcbff, 0xbe923161, 0xbe81f2c8, 0xbdb0f717, 
    0xbd51cfbe, 0xbea8ebed, 0xbe47c792, 0xbbbc0b5a, 0xbe08b87b, 0x3d2b6e18, 0xbed6409d, 0xbe1848b9, 
    0xbdb8c925, 0xbe727629, 0xbeb06ff2, 0xbe2120ec, 0xbec5238d, 0xbe37be7c, 0xbe80ceaf, 0x3e1e0916, 
    0x3dccc3eb, 0xbdc8b484, 0xbec808db, 0x3d1044da, 0xbd6806a9, 0xbe54246e, 0xbe9833f5, 0x3c0e778f, 
    0xbdccbd98, 0xbe57db3c, 0xbe49940b, 0xbe69991f, 0x3e7ace9a, 0xbf3fbc84, 0xbd774e63, 0xbe8aa66a, 
    0xbeca4ef0, 0xbe83e032, 0x3ef1eb1a, 0xbf46791d, 0x3efdc95b, 0xbe42f1fb, 0xbe6e5c1c, 0xbffbaa10, 
    0x3db0fa4f, 0xbfc2abfa, 0xbf1c3fb7, 0xbff212bc, 0xbce927bb, 0xbda538ff, 0xbd8abc4f, 0xbe57a5dd, 
    0x3e3593c6, 0xbec0d389, 0xbd6b83a1, 0xbe0efc61, 0xbda8211e, 0xbe9e5bf2, 0xbe123bf9, 0xbf347bbd, 
    0x3e57a8d4, 0xbdc01c59, 0xbf67af3d, 0xbefdc4fd, 0xbba44881, 0x3eed54f6, 0xbe84de37, 0x3eb86abc, 
    0x3ec2c7a1, 0xbf0551dd, 0xbf2c7925, 0x3ec88fbb, 0xbe8a1db2, 0x3f0d18f6, 0x3e1b2f2d, 0x3dd3185f, 
    0xbf5ba2c9, 0xbe9e4406, 0xbf48e028, 0xbcf96fb0, 0xbe96057b, 0x3d8fee1c, 0x3ea44172, 0x3ea1042a, 
    0xbf7a4033, 0xbd820b30, 0xbf0a0a97, 0xbf044a77, 0x3e1fc933, 0xbd8f583c, 0x3da04e8a, 0xbe014fd4, 
    0xbd89fb2e, 0x3eead382, 0xbf557e31, 0xbf37cc78, 0xbecc3696, 0xbe941b05, 0x3f097f47, 0x3d670ec1, 
    0xbf297689, 0xbd73b623, 0x3eaf4407, 0xbeda2f13, 0xbd9c313b, 0xbdc80ee9, 0x3dc19d5f, 0xbf73ee7b, 
    0xbc135f42, 0x3ecd3707, 0xbe384f54, 0xbc27d53d, 0x3ddbc578, 0x3e42b780, 0x3ee57d38, 0xbf5c996c, 
    0x3dc766d6, 0xbe7990d3, 0xbec72443, 0xbe9a9b63, 0xbf6d5f95, 0x3e5f656e, 0x3e04791d, 0xbdbf56be, 
    0xbf47a904, 0x3dcc5a3a, 0xbf0e450d, 0x3ccb5945, 0xbf8be7be, 0xbee46824, 0x3f168929, 0xbc017f1f, 
    0xbf2da64f, 0xbf3f6f00, 0xbe511d2b, 0xbf170482, 0xbf4db407, 0xbee96650, 0xbd5947a2, 0x3dae064e, 
    0xbf5e1e71, 0x3edd2e6f, 0x3e760c91, 0x3e0f6643, 0xbf36bae8, 0xbdaa38a6, 0x3eba11ec, 0xbcae03e1, 
    0xbf02a777, 0xbea569f0, 0xbcef9fd9, 0xbc96f468, 0xbea70b43, 0xbe7e161d, 0xbea3c390, 0xbd1b4023, 
    0xbf07b426, 0x3db943f9, 0xbdf2c276, 0xbc8fa2e5, 0xbf00c88b, 0xbf057eaa, 0x3f096e0d, 0x3eb2d661, 
    0xbe1c1935, 0xbf451bab, 0xbb901b5a, 0x3ed45a41, 0xbee43276, 0x3d63e2cb, 0xbb9fd175, 0xbe17c344, 
    0xbf7cf241, 0x3e8eb9fd, 0xbf55f30e, 0x3dc16496, 0xbdedf3e2, 0x3e37b2f0, 0x3e049dfd, 0xbdb5d007, 
    0x3ec946af, 0x3ee1f734, 0xbe24222f, 0x3e4495d1, 0xbed816ef, 0xbe539312, 0xbe435250, 0xbf20d871, 
    0xbdceae42, 0x3e149199, 0x3ec367e7, 0x3f085690, 0xbe59ef8c, 0x3e4af80a, 0xbe2b173a, 0xbd70caf1, 
    0x3db01145, 0x3decdf56, 0xbf8fd256, 0xbe913756, 0xbf010f06, 0xbea5d28d, 0xbea4b70e, 0x3dd784e7, 
    0x3e231d96, 0x3ed23ddd, 0xbf67dccc, 0xbee2b172, 0x3e0fb82b, 0x3e5e22e3, 0x3e4afb00, 0x3f36281f, 
    0xbb7ec1cd, 0xbf103fc1, 0x3e976028, 0x3e8c530c, 0xbe04c2d5, 0x3ecbbc17, 0x3cbddeac, 0x3dfb2da1, 
    0xbe3c954d, 0xbee86091, 0xbf7b05ad, 0xbea836d0, 0xbf59456c, 0x3e976376, 0x3e0b416d, 0xbead0282, 
    0x3f0909f5, 0xbe8bf635, 0xbf58b146, 0x3dfa9244, 0xbe974022, 0x3e146788, 0xbe1e5ef6, 0x3e2e0de8, 
    0xbec45ff0, 0x3ebe33c6, 0x3dc62852, 0x3eacc219, 0xbf21ab69, 0xbed2fc6a, 0x3eb1960b, 0x3e9ecf03, 
    0xbeb33b5d, 0x3e16ea08, 0xbd9cee59, 0xbea6e8b6, 0xbdd706e3, 0xbd86883e, 0xbe5c94fd, 0xbec527e0, 
    0xbde72f96, 0x3e54d142, 0xbf30788d, 0x3eedb09f, 0x3ea538f0, 0x3ed400a4, 0x3e305a1b, 0x3d44c102, 
    0x3d07204f, 0xbf12d77e, 0x3e9e7d88, 0xbf0ab8ac, 0xbf2a9eae, 0xbe545fd7, 0xbf1fb54b, 0x3d8d941c, 
    0xbf720aef, 0x3d81314f, 0x3e95b4fa, 0x3f0af59b, 0x3e0aaf34, 0x3e866242, 0xbd94232d, 0xbe09adc3, 
    0x3ed7834a, 0x3d909841, 0x3e201dec, 0xbe8765ff, 0xbf13fe65, 0xbe6da00a, 0xbe871e14, 0xbe30b525, 
    0x3e514dd9, 0xbd8c23f2, 0xbd49680c, 0x3eefe670, 0xbafcad6b, 0x3e9939a8, 0xbbb6973c, 0xbe8685ea, 
    0x3ec8adf3, 0x3e2be7be, 0xbe60f23c, 0xbe1b88bc, 0xbdd1f0ac, 0xbbd1b0bc, 0xbeaad1a3, 0xbdadca74, 
    0x3e0d82c4, 0x3d481d2a, 0xbd18d063, 0x3eb95398, 0x3d110b6a, 0xbe2bff2e, 0xbd9f4afb, 0x3e7f490f, 
    0xbe225ddd, 0xbe28a72c, 0xbde570a9, 0xbeb16c26, 0xbe8685b3, 0xbe36e0f9, 0xbf406db9, 0xbea43978, 
    0x3f01cc0e, 0x3ecd835f, 0x3df23f2d, 0x3d04290e, 0xbea28501, 0xbe8cfddd, 0x3de6c668, 0x3e76aa74, 
    0x3e875704, 0x3efc6f5b, 0x3f146f45, 0x3efb9918, 0x3ef30c7f, 0x3d168492, 0xbe47d9c9, 0xbed9b823, 
    0x3e95b39d, 0xbf674ad3, 0xbf1c46aa, 0x3e74d42c, 0x3e06fed6, 0x3e878bed, 0xbd78aee7, 0xbeb69308, 
    0x3c9d199d, 0x3d381443, 0x3df01f2a, 0x3e065db0, 0xbd87b6ac, 0x3beb8495, 0xbee09998, 0xbf46b9a1, 
    0xbc1e824a, 0x3da5213a, 0xbd465063, 0xbcc8fea6, 0xbe73360c, 0xbf6e685d, 0x3e36d7fa, 0xbf6d800a, 
    0x3d1d1fff, 0xbd374aae, 0x3e9531d0, 0xbe9780eb, 0xbdf33dc5, 0xbecf440c, 0xbe511d6a, 0xbf7ff9c7, 
    0xbc3bb59c, 0x3f051fa0, 0x3dfb9ae6, 0xbec3a7eb, 0xbe9f54f4, 0xbf8e1837, 0xbf1bf0b6, 0x3e119d60, 
    0xbecbc382, 0xbf2b2bb0, 0xbef252f4, 0x3f138534, 0x3f2f5545, 0x3d42fa03, 0xbe937604, 0xbd7155ae, 
    0x3db010a2, 0xc00e02ad, 0xbfb39748, 0x3ed30bee, 0xbf9fbdd5, 0xbfc64ebf, 0xbfb6465d, 0xbe399fb5, 
    0xbd8fabff, 0xbe818929, 0xbf260b26, 0x3e539fa5, 0x3eabdccd, 0xbee38efe, 0xbe457e08, 0x3d356ffe, 
    0x3d0d6d9c, 0xbf85f812, 0xbf2566dc, 0xbeafc041, 0xbec397c2, 0xbf81f2d0, 0xbf32aaef, 0x3db15915, 
    0xbf53f629, 0x3cd4121d, 0x3d9309d1, 0xbe613b76, 0x3eb6a8ce, 0xbfbb0c01, 0xbf0d2625, 0x3d82a7f9, 
    0x3ee7391d, 0xbf1e4586, 0xbf9d4fcd, 0xbf077853, 0xbfdd88b8, 0x3ee5169b, 0xbe363b4c, 0xbdc3598e, 
    0x3ea037a2, 0xbf14a9c6, 0xbe672e82, 0x3e460940, 0xbf9d250d, 0xbe94e41d, 0xbede1c7f, 0x3e222d1d, 
    0xbeb61ef7, 0x3f1c0859, 0xbd1ad712, 0xbf4af3e2, 0xbf3fc6d4, 0x3d4f4f58, 0x3dcfe8ac, 0x3e202e33, 
    0x3e28e5b0, 0xbef0ee5c, 0xbed188be, 0x3d0cd06d, 0xbe9088dc, 0x3e363778, 0xbe4a4d5c, 0x3ce919fc, 
    0x3d4b01b9, 0x3e0ec8d0, 0xbf4c7415, 0xbf0da1be, 0xbec2ed32, 0x3ec4e700, 0x3dc8e36c, 0xbdd1204e, 
    0x3e92a86e, 0x3f1141b2, 0xbe2810a0, 0x3e24b160, 0xbef6e939, 0xbdd19d89, 0xbe9e7467, 0xbfc7ba6b, 
    0xbe14efc6, 0xbe6c1791, 0xbe244686, 0x3e2f5708, 0x3dc27aab, 0xbe31cc0b, 0xbf3f99f4, 0xbd03d07f, 
    0x3eb368f0, 0x3eb81923, 0xbf43f7a2, 0xbead916b, 0x3c3c1b2e, 0x3e97911d, 0x3d585332, 0xbeedfa9b, 
    0x3e9b36c2, 0xbf5b33d6, 0x3e38d07a, 0xbf5bd3ca, 0xbbfb53e7, 0xbee317a5, 0xbf42d2d5, 0x3e3c8e8d, 
    0x3e918886, 0xbf14054a, 0x3e812063, 0x3e895c7d, 0x3e131f49, 0xbeb58bdc, 0xbf60db2c, 0xbe3c8c37, 
    0x3c599f15, 0xbdc609c7, 0x3e465aab, 0xbe1e0708, 0x3db23b8f, 0x3e9d7a05, 0xbf55eadf, 0xbcec7daa, 
    0x3d46a600, 0xbf12729a, 0x3ed41b79, 0xbf1f9834, 0xbe308dfb, 0xbe069f90, 0xbd2034f2, 0xbf15b20a, 
    0xbf0041e4, 0xbfd19fb2, 0xbf3e28be, 0xbeb23c0a, 0x3e8823ac, 0xbec62e00, 0xbd8f46c3, 0xbe0a9130, 
    0xbf199552, 0xbe6af2f5, 0x3e45c741, 0xbe1c7bc1, 0x3e98d8c3, 0xbe8fb9a5, 0xbe973d2c, 0xbf0769e0, 
    0x3f0a10f9, 0xbe4fd8ed, 0xbecd3984, 0xbee662f6, 0x3d300fed, 0xbe2ebdb0, 0x3b848693, 0x3e7301b0, 
    0x3dba49b7, 0xbf5bf3d1, 0xbe358755, 0x3e431696, 0x3d957044, 0x3e5d75fd, 0xbe86fa5d, 0xbf0f4536, 
    0xbe3c0371, 0x3e9d14c8, 0x3d96dd00, 0xbc079611, 0xbf516349, 0xbefe70e9, 0xbd7b18e0, 0x3f376b1e, 
    0x3d49fcdb, 0xbd53072d, 0xbefd8261, 0x3e9087d0, 0x3e6fd612, 0xbc41a54b, 0xbee202ad, 0xbec81b98, 
    0x3e91c7e6, 0x3df58ea4, 0xbe38c0d1, 0x3e9e3a75, 0xbeafb15f, 0x3e7bb4cb, 0x3c169d6f, 0xbe7a2994, 
    0x3e765c2b, 0xbd9b83a1, 0xbec99553, 0xbde67469, 0xbf03ca1a, 0x3d82dbaf, 0xbe852937, 0xbe6905b2, 
    0xbe8a8c23, 0x3d293788, 0xb956f862, 0x3d2e5c66, 0xbe1c358f, 0xbe6d2ce0, 0x3e4ebafe, 0x3c6a7338, 
    0xbea66fa5, 0x3e205a57, 0x3ece504a, 0xbe3d274f, 0x3e58183b, 0xbe8b7d00, 0x3e209643, 0xbe47823d, 
    0xbce09b2e, 0xbc95ea75, 0x3e63e370, 0xbe10773f, 0xbf2f0fad, 0x3f388533, 0xbe16a8d2, 0x3cb5c5b1, 
    0xbea79f08, 0xbd1ac76c, 0xbeec8de6, 0x3e25d08e, 0x3f1b6acb, 0x3d18635c, 0xbe9d60d4, 0x3e4e4f8f, 
    0x3da42ed8, 0x3dcfa525, 0x3ea707a3, 0xbd4e8722, 0xbdeec343, 0x3e6406fc, 0x3d9896e7, 0xbf61bbbf, 
    0xbdd54418, 0xbe512e43, 0xbe7caf06, 0xbf938528, 0xbf933a61, 0xbd029849, 0xbe755cfd, 0x3e5049d7, 
    0xbe03410d, 0x3ed762a7, 0xbe6fa9d3, 0xbd1a426d, 0xbe11daab, 0x3e822621, 0xbf0f44b7, 0x3ed0d7f5, 
    0xbd83eaf8, 0xbeb629e8, 0xbebca4be, 0x3df753c5, 0xbf37f6d2, 0x3ebe59ba, 0xbeb445f4, 0x3efdc411, 
    0x3e2a6ea2, 0x3df1e884, 0xbe8ea379, 0xbf368bc6, 0x3e9caa9d, 0xbeaac0e1, 0xbe05c1d3, 0x3d953045, 
    0x3e414aed, 0xbea0e747, 0x3d8e7fee, 0x3ea4755f, 0xbe2ec495, 0x3e00723f, 0xbf00d08c, 0xbee0d8f3, 
    0x3dce539c, 0xbeeaac3e, 0xbf098cf8, 0xbe28fe2a, 0xbfba275e, 0xbe50466b, 0x3eec36bf, 0xbd9f3410, 
    0xbf3bdf7f, 0xbf4c3266, 0xbe13b62e, 0xbef3f548, 0xbf8810fe, 0x3cb5799b, 0x3e8f20c5, 0x3ea22cfc, 
    0xbfb1421a, 0x3e8d4ef6, 0x3e904f60, 0x3e9280d5, 0xbf91ca11, 0xbd347ee3, 0x3e82ae84, 0x3e88c28b, 
    0xbef69f80, 0x3d790db4, 0xbe296b6f, 0x3cb5a55f, 0x3d685c20, 0x3e0e45c9, 0xbe354a8d, 0x3e3fc18a, 
    0xbeeea8aa, 0xbceb99de, 0xbecdf886, 0x3db904db, 0xbf9304b4, 0xbe743259, 0x3ee3ee22, 0x3ef8efff, 
    0xbe708456, 0xbf772e5b, 0xbcfde3f3, 0x3f019997, 0xbf2a7619, 0x3ea0a005, 0xbc2354e5, 0xbda4e458, 
    0xbf52c5bd, 0xbe50a7e0, 0xbf1885f7, 0xbdce5bba, 0xbd2644aa, 0x3ef4fca5, 0xbf63c9ba, 0xbe117351, 
    0x3ed76dde, 0xbf1d2cde, 0xbf278de9, 0x3d074dbf, 0xbfa7eaab, 0x3e24bd0c, 0xbb8a3a1e, 0x3e5914c0, 
    0xbf0411af, 0x3ec1bf43, 0x3ebafed3, 0xbf40c735, 0xbe5f9f78, 0xbe6fbc4c, 0xbf3065e6, 0xbe263f0f, 
    0xbdec55ac, 0xbf03d207, 0xbea8425d, 0x3e02b248, 0xbf1a468b, 0x3ea90d81, 0xbd9f707f, 0xbcf36b86, 
    0xbf12d5ae, 0x3c62f9e4, 0xbe8654e6, 0xbecdc7f2, 0xbe28442f, 0xbf0f75d4, 0xbe52f232, 0xbe95090e, 
    0x3e7561d8, 0xbe2ce056, 0x3dbd898a, 0x3e122369, 0xbedabb20, 0x3d4a8ae8, 0xbf0f4be9, 0xbf163ef1, 
    0xbe87fd07, 0xbf00303d, 0x3e827614, 0x3dda930c, 0x3e4ff5c5, 0xbebf4eb2, 0x3e36b13c, 0x3d4814ef, 
    0xbe1ec258, 0xbeba6753, 0x3ed73a2d, 0xbe34574c, 0x3e1e24ad, 0xbea5cfdd, 0x3d84afb1, 0xbe918a75, 
    0xbe842f28, 0xbf2175f8, 0x3d22a25b, 0x3d8aa93d, 0xbea18061, 0x3dc64d9e, 0x3e61259e, 0xbe9bf53c, 
    0x3d695d28, 0x3d835f63, 0x3c1617ab, 0xbf132644, 0xbedf4491, 0xbecc022b, 0x3dc3401b, 0xbe78ae44, 
    0xbeee6897, 0x3dc3065c, 0xbdd4e810, 0x3e707697, 0xbd9b4bcf, 0xbb228fb8, 0xbe74105f, 0x3e4e9ba1, 
    0xbd1588c5, 0xbd90d94a, 0xbe969f34, 0x3f031fb9, 0xbe6bff3b, 0x3e342949, 0x3daabd47, 0x3e478f93, 
    0xbd2f655f, 0x3dde7098, 0xbed642e4, 0xbec8e7a9, 0xbe2172ce, 0xbe189955, 0xbc9ed4d1, 0xbe5158b9, 
    0xbe1f88fe, 0x3d87cd7b, 0xbd633de4, 0xbe0ffcde, 0x3dacd898, 0x3a65cfc4, 0xbd83aeac, 0xbe34d048, 
    0xbe319e04, 0x3d050591, 0xbb63f19f, 0x3d8f1b8a, 0xbd9b2a78, 0xbc9a9b82, 0xbd12e26e, 0x3e14160f, 
    0xbe454ffd, 0xbdd70163, 0xbb077ce1, 0x3e19764b, 0xbe345eb6, 0xbdd90764, 0xbe03f333, 0xbe0790f0, 
    0xbe0f0ac2, 0xbe619869, 0x3c8d5077, 0x3d6df10f, 0xbcee754c, 0xbdde3172, 0xbe284d5e, 0xbd767847, 
    0xbe26bb5f, 0x3ce60483, 0xbe0890fa, 0xbe174eab, 0xbcf558d1, 0xbe80be92, 0xbe2604cb, 0x3c4c908b, 
    0xbddee33a, 0x3dcfc1a5, 0xbc55698e, 0xbe58724f, 0xbe8dc6d6, 0x3ea9b389, 0xbe1b7e5b, 0xbe8b6681, 
    0xbd51eb06, 0x3dc8f1fd, 0xbe5f2aad, 0xbd9c9a79, 0xbf4851c9, 0xbd0a6706, 0xbea5fbae, 0x3ec8ed0f, 
    0x3e74756c, 0x3e89a391, 0x3e5f8884, 0xbf11893c, 0xbb42f503, 0xbc8d2e81, 0x3e321142, 0x3e023149, 
    0xbd9bc9e7, 0x3e13306d, 0x3d5db9db, 0xbcf376a8, 0x3d34584a, 0xbea64400, 0xbf5d1827, 0xbe1f4d48, 
    0x3e304efc, 0xbd88845f, 0xbf2f1212, 0xbcca55dd, 0xbe6317d8, 0x3d8799ef, 0xbe22e7a0, 0xbe5fd84d, 
    0x3e1c168f, 0x3f1a2a88, 0x3d98e1aa, 0x3d8c987c, 0xbe7ea9ee, 0xbdd22035, 0xbea56477, 0x3ef76d7f, 
    0xbb727515, 0xbed110b7, 0x3dc25bd1, 0x3eca0b04, 0xbe405ec5, 0xbd9420b8, 0x3ed6e5fc, 0xbe59a3b9, 
    0xbf297582, 0xbf173f11, 0xbeff459f, 0xbdf5c8bf, 0x3e6e9073, 0xbc3a7931, 0xbd501f8d, 0xbee45f2d, 
    0xbec5da11, 0x3ebbc933, 0xbf36b9ce, 0xbdc25402, 0x3ddab8be, 0xbee07d70, 0x3e94701b, 0xbeb7e509, 
    0xbeef6382, 0xbde510bc, 0xbdea66e1, 0xbec3dc69, 0xbde54735, 0xbe22c559, 0xbe4290da, 0xbf299e3f, 
    0xbe7930d0, 0x3eaa6e4d, 0xbdb24275, 0xbd496c01, 0x3db9e370, 0xbf24ec47, 0x3f06865e, 0xbf8f651d, 
    0xbe1483c2, 0x3caeb735, 0xbddae79d, 0xbe1af282, 0xbf13f0db, 0xbdca925f, 0x3e022c7c, 0xbe0d681a, 
    0xbf33042c, 0x3eb972fb, 0xbea67749, 0x3e44fa3f, 0x3e8ece34, 0xbf1a685b, 0x3e4de9d3, 0x3e695a5d, 
    0xbf1d8adb, 0x3ec6eb68, 0x3ecc84a2, 0xbf41699a, 0x3ecad165, 0xbe3bf6c7, 0xbe95906d, 0xbf917237, 
    0x3f081efd, 0x3d978782, 0xbd9a35b0, 0xbeda943e, 0x3e0854a9, 0xbe1d91a0, 0xbdc1e90b, 0x3d97f406, 
    0xbe09924d, 0x3e9bda04, 0x3d15d82c, 0xbcd9e796, 0xbe8bec06, 0xbda85ee9, 0xbe33c7c4, 0x3daf7bf8, 
    0xbddf136b, 0x3e7723f6, 0x3de52b44, 0xbea38638, 0xbf6cbe83, 0xbefb510e, 0x3e8ae5d1, 0xbd36f8a7, 
    0xbf3acb62, 0x3f097e9a, 0xbe7ecf60, 0xbf196c50, 0xbda61239, 0xbed06f3e, 0xbeae1d1a, 0xbdf98392, 
    0x3ece8642, 0xbdc12efa, 0x3e9694da, 0x3ea8f90a, 0x3df34d50, 0xbe2a4cf8, 0x3e59666c, 0xbf1dd0ac, 
    0xbf2b5bf3, 0x3e58e7e8, 0xbeb1274a, 0xbf074214, 0xbd5a6f89, 0xbdfad815, 0xbe231ed9, 0xbf18c8f6, 
    0x3e53a96a, 0x3e5b1617, 0xbf04f433, 0x3e101910, 0xbf00c132, 0x3d8c0874, 0x3f09064e, 0xbeeb09ec, 
    0x3e4ef31e, 0xbea1f66e, 0x3be2d9e9, 0x3c0f7b1f, 0x3db00cae, 0xbe12599e, 0x3d306606, 0xbe37bea6, 
    0x3da6da7b, 0x3dd41662, 0xbde754d0, 0xbe161452, 0xbef40c45, 0xbf14107e, 0x3f19ac90, 0x3f110484, 
    0x3ec1eef4, 0xbd456bb2, 0xbeb16c99, 0x3ded4488, 0x3d887a48, 0x3e5f73a6, 0xbee2e5fa, 0xbf5961a2, 
    0xbee7d077, 0x3e2ec4a8, 0xbeec60fb, 0x3e142386, 0x3dbf1242, 0xbe6dd4c7, 0x3e4bde8a, 0x3e4c8392, 
    0xbf529759, 0x3e042f39, 0x3e2f8ad2, 0xbe58fe71, 0xbd4c7c6d, 0xbef71d7d, 0xbeca07b7, 0x3eb8d6ac, 
    0x3ec2c1df, 0x3b911d14, 0xbe486413, 0x3d914439, 0x3da07cfc, 0x3cc2d7f3, 0x3e892a38, 0x3e6e267f, 
    0xbf19a76f, 0xbcd23bb3, 0xbd0d6f7f, 0xbf1df246, 0xbd3689c3, 0xbedd0833, 0xbee21feb, 0x3e90d8c2, 
    0x3ddf4083, 0x3d6ec02f, 0x3e1a93ba, 0xbdfc4efb, 0xbe3b6720, 0x3de317c8, 0xbe83c84e, 0x3e563986, 
    0xbf2f0d6a, 0x3e8490bc, 0xbf2d125a, 0xbe987320, 0x3e8d76d8, 0xbee7eadd, 0xbd83eb48, 0x3e3f6c05, 
    0x3e953e15, 0x3d92432b, 0xbe99c391, 0xbd1018cc, 0xbf3130f4, 0x3db7d7ba, 0x3dba30fc, 0x3bd02cb9, 
    0x3f496a14, 0xbef7f9c9, 0xbda8b4f5, 0x3dae9e74, 0xbe97f7d5, 0xbdadc4c2, 0x3cc29906, 0xbd0a6018, 
    0xbe39345d, 0x3e225ac5, 0x3e8efc1c, 0x3e77a42b, 0xbeb853db, 0x3e7166c6, 0xbdef10d4, 0xbda22745, 
    0xbe9694bb, 0x3e145172, 0xbf0088f4, 0xbf1278d8, 0xbe480dba, 0xbf4af81c, 0xbe6b6b83, 0x3ca7d580, 
    0x3c8b33a8, 0xbdbeba6b, 0xbeee84fe, 0x3e7fc383, 0x3f100fd2, 0x3f0ca445, 0x3dea8f7d, 0x3e36cf8a, 
    0x3e842460, 0xbf5575c5, 0x3eaf3882, 0xbf8f2e16, 0xbf991846, 0xbef2c468, 0xbf520a67, 0xbec554d4, 
    0xbeba6212, 0xbe87af39, 0x3d0625a4, 0xbee86135, 0xbe086530, 0xbe232a46, 0xbe607d0e, 0xbe7be8ec, 
    0xbc033122, 0xbe2ce970, 0xbe5babe6, 0xbd6f0f0e, 0x3dbd0bc4, 0xbc5e7ca4, 0xbe0b6190, 0xbe6c99ce, 
    0xbe43dfb8, 0x3da08bf7, 0xbd25bee6, 0xbda29c9e, 0x3d23737d, 0x3e0918d8, 0x3dd47ab0, 0xbcdf1421, 
    0xbe24b1b4, 0xbe023dc4, 0xbe1acbf8, 0x3dfb0573, 0xbdefc0fd, 0xbe3f8541, 0x3bd47b14, 0xbe262b3c, 
    0xbe6dda7a, 0xbc8e0d52, 0xbdcfb1b7, 0xbe43e17b, 0x3c9245f1, 0xbe555ebc, 0xbd4693cd, 0xbe2df684, 
    0x3c2bc8fa, 0xbe6b5320, 0x3dd2a73e, 0xbe1cef9a, 0x3c99d6d5, 0xbb89b381, 0xbe019af8, 0x3dadc29a, 
    0xbc983330, 0xbe0c3970, 0xbe092326, 0xbe106837, 0xffffc01a, 0x00000004, 0x00000010, 0x00000001, 
    0x00001f40, 0x00000001, 0x00000010, 0xffffc036, 0x00000004, 0x00000010, 0x00000001, 0x00000001, 
    0x00000fa0, 0x00000010, 0xffffc052, 0x00000004, 0x00000010, 0x00000001, 0x00000fa0, 0x00000001, 
    0x00000020, 0xffffc06e, 0x00000004, 0x0000000c, 0x00000001, 0x000007d0, 0x00000020, 0xffffc086, 
    0x00000004, 0x00000180, 0xc116c25f, 0x40c3f5da, 0xc084294e, 0xc00e7798, 0xc11a074c, 0x3f148c14, 
    0x41cbeff7, 0xbee120dd, 0xbff023cc, 0xc13bfde3, 0xc1aedae6, 0x413148c3, 0x41265240, 0x40cfc085, 
    0xbf87fd5e, 0x40ed6d91, 0xc146ec08, 0x3f5718be, 0x40c03992, 0xc112838a, 0xc1ac2b8a, 0xc003d0f3, 
    0x402dac1a, 0x3fc2a4f3, 0xc1af4ea7, 0xc151616f, 0xc1811a5a, 0xc1014d3b, 0x41d2fed2, 0x413028ed, 
    0xbffa8916, 0xc09a909d, 0x40e14a00, 0x405ebe65, 0x3f487b3c, 0x40127339, 0x407f8ed5, 0x408b9d61, 
    0x40bc6951, 0x3ff4935a, 0x405ddf99, 0x3ecdad92, 0xbf0bf554, 0xc0331929, 0xc0c0845d, 0x409c2adc, 
    0x40505db3, 0xbfb7e11b, 0xc1251742, 0x410cda30, 0xc10469d2, 0xc0c3d57e, 0x4116355b, 0x3fcb0bc7, 
    0xc1303fc0, 0x41118007, 0x41f6fabd, 0xc1347297, 0x410f6457, 0x41141c3d, 0xc13530dd, 0xc0ed8855, 
    0xc1d91271, 0xc1318ffe, 0x4003de35, 0xc0d91b6d, 0xc00248c5, 0xc121e168, 0xc1a76328, 0x3f1353de, 
    0xc0bb1eb3, 0x3f2c52be, 0x4141b651, 0xc01ab18b, 0xc098527d, 0xc038881f, 0xc0a258af, 0xc0f95d2c, 
    0xc16e995c, 0xbfba5a8e, 0x41bf9981, 0x4135faa3, 0xc07b0a13, 0xc0e64b2f, 0x40efdafd, 0x3e143560, 
    0xc135b10d, 0x3f25facc, 0xc0de4db4, 0x40b9b19b, 0x3f7624a2, 0xbfa5845c, 0x4170f139, 0x40b0c364, 
    0x3ffcbff6, 0x40df4f35, 0xffffc212, 0x00000004, 0x00000c00, 0xbc7008bc, 0xbf17f359, 0x3dbab136, 
    0x3e580175, 0x3da7600f, 0xbe910b5e, 0x3e7505e4, 0xbe1f4460, 0x3c99765d, 0xbca6879c, 0xbec47671, 
    0xbe4d35a7, 0x3e966ef7, 0xbd125e3e, 0x3e09737e, 0xbed22f42, 0xbc80de99, 0xbec71462, 0xbda9a894, 
    0xbdfeee08, 0x3ac47001, 0xbe4b7eae, 0x3912ad73, 0xbe592383, 0x3e07331d, 0xbe3b7218, 0xbdf0d346, 
    0xbe868980, 0x3ea818c9, 0xbe287a60, 0xbeb5550b, 0x3d57ee3c, 0x3d0d672c, 0x3ededfbb, 0x3e084707, 
    0x3de1c460, 0x3d36a4a5, 0x3e4f6acd, 0xbeb267c7, 0x3d93ba3f, 0x3d70b758, 0xbda40182, 0xbd0bbdf2, 
    0xbc4d3e51, 0xbe52a054, 0x3cfb2290, 0x3e62fe07, 0x3e95b41d, 0xbe272e2d, 0xbc357ce0, 0xbe8d9a9b, 
    0xbd02a2fe, 0xbe733e63, 0xbe7753c4, 0xbe6b44fb, 0x3d9fda4f, 0x3d441291, 0xbd73552d, 0xbe4d231b, 
    0x3e13b3a5, 0x3dd1fd04, 0xbd8c9092, 0x3e63ad27, 0x3d0cee1d, 0xbcee577f, 0x3dd5d80f, 0x3b0ace46, 
    0xbd7a20f1, 0x3d894f94, 0xbe433b6f, 0xbec53a8b, 0xbd434d6b, 0xbe37a9d5, 0xbe8a2073, 0xbeb06856, 
    0xbc4c7578, 0xbe35bca2, 0x3e130ba3, 0x3deeb336, 0x3d8a3515, 0x3ea58d70, 0x3c86b38e, 0x3df694f8, 
    0x3da4b253, 0xbd610241, 0xbc1bbfe6, 0xbdae9745, 0xbeca1253, 0x3e078c9f, 0xbdda9a83, 0x3eed0b42, 
    0x3de6c145, 0xbf03082e, 0xbc0edc9f, 0x3e9cb660, 0xbe8e9df0, 0xbdc232f7, 0xbd96d0bd, 0xbe374692, 
    0xbc9205d1, 0xbbc8486e, 0xbf1d96c2, 0x3d4163a0, 0x3dd906e0, 0xbd95a0cf, 0xbcb8d4cc, 0xbd554431, 
    0xbe416156, 0x3d23bb41, 0xbca29037, 0xbecc2db6, 0x3d67da51, 0xbd6200f0, 0xbe1038b5, 0xbe66ebc8, 
    0x3c9f8238, 0xbd017553, 0xbd04454f, 0x3dc6ecb4, 0x3ccbf00a, 0xbc8166cd, 0x3dff2fb8, 0x3da1a504, 
    0x3c9e625d, 0x3df65ffb, 0xbe6cf404, 0xbe08424e, 0x3e39379e, 0xbe034e4d, 0xbdc7046b, 0xbead0dc2, 
    0x3d748c2f, 0xbcf11f31, 0xbd6b0b0f, 0xbd19265d, 0xbdbe6f78, 0xbe163c1c, 0x3caed52d, 0x3dd6fd2b, 
    0x3d829fc3, 0x3e21b7ec, 0xbe1ede4e, 0xbe394ff7, 0x3e750430, 0xbe8c855c, 0xbe923c3b, 0xbd6a199a, 
    0x3dc36a80, 0xbd8742d6, 0x3cc57715, 0x3d846963, 0xbd314b41, 0xbe3bf183, 0xbe426815, 0xbe41d4f6, 
    0xbd1601ec, 0xbe85ec60, 0xbe7df1e1, 0xbe8395a4, 0x3dac0c6e, 0xbe94f527, 0xbe8c17d0, 0xbc1a98c7, 
    0x3dd6ea09, 0xbdcab75c, 0xbe2d922b, 0x3e015f17, 0x3dcc3cd5, 0xbe85f4db, 0xbe406801, 0x3cf72dff, 
    0xbd495846, 0xbecba50d, 0xbe6a1322, 0xbc04010d, 0xbe05ed39, 0xbdd4a660, 0x3e12f404, 0xbe2c10ae, 
    0x3e8e3dea, 0xbe692084, 0x3ddc4046, 0x3d2e58c4, 0xbe10c0ea, 0xbc94c4d1, 0xbd09f63f, 0x3eb9501c, 
    0x3e338a8b, 0xbe88a9a9, 0xbeb2c866, 0x3da0a090, 0x3d9aabc8, 0xbdb3ef81, 0x3e95fce9, 0x3dd426f0, 
    0x3d6e45a9, 0x3d91c236, 0xba92a017, 0x3d0e6baa, 0xbd591b7f, 0x3e841e75, 0xbec72cec, 0x3e8e2869, 
    0x3e1a093d, 0xbeb61d45, 0xbca04a98, 0x3e8136e3, 0x3e865db5, 0x3c756841, 0x3ddd287d, 0xbdfceabf, 
    0xbbb81442, 0x3e795671, 0xbe06623c, 0xbdb7fee5, 0x3c62765e, 0x3e477aca, 0x3d2d0439, 0xbd12c7c1, 
    0xbdc91c38, 0xbe59d017, 0x3cef076d, 0x3e971aa6, 0x3ea8fc7a, 0x3e4e2dad, 0x3dbc2584, 0xbe5d5730, 
    0xbe01a49c, 0x3d2e5d94, 0xbe3a9e29, 0xbe0adb89, 0xbdc16922, 0x3e0946de, 0xbe02e191, 0x3e499f0a, 
    0x3e4f8869, 0xbd0aa8d8, 0x3d35b206, 0x3e0b47c2, 0x3d39044c, 0xbdccf5bc, 0xbe9437c7, 0xbe7de98e, 
    0xbe3d92ad, 0xbdba1d3e, 0x3e422906, 0xbd4aabda, 0xbdd9f40d, 0xbd9910cb, 0x3ea3448f, 0xbeabc038, 
    0x3f2dfbc4, 0x3deebcee, 0xbeaec757, 0xbe1182e3, 0xbe34edf4, 0xbd30093e, 0xbe5552a1, 0xbccd65db, 
    0xbd30b680, 0xbd65e98b, 0x3d0b905e, 0xbdacf77a, 0x3c7ef65a, 0xbe4d2eb0, 0x3ebb0d43, 0xbc7f4c6e, 
    0x3f37064f, 0xbbad6adb, 0xbe006769, 0xbdfd113b, 0x3b97c796, 0xbe14140d, 0x3dad7a76, 0x3e53ef22, 
    0xbd46490e, 0x3b3cd86c, 0x3d0cc689, 0xbe88509e, 0x3e233a39, 0xbe57613b, 0x3e2c118b, 0x3e0bb22d, 
    0x3f1f1d86, 0xbd23cb07, 0x3d331c18, 0xbd6f1bca, 0xbec491c2, 0x3e0637cd, 0xbed3e702, 0xbd508164, 
    0xbe1d05d6, 0xbe1d3251, 0xbf294718, 0x3e69be8c, 0xbf3b8845, 0x3dfcf349, 0x3db0c08b, 0x3cae56eb, 
    0x3e05f530, 0xbdd2febf, 0xbd8ae9e6, 0x3e91779f, 0xbe6008ab, 0xbe946143, 0xbdac714a, 0xbe400046, 
    0xbe51b6e3, 0x3cba044c, 0xbed1026f, 0xbe2dbbc1, 0xbcf20f9b, 0xbd825687, 0xbd2933a3, 0xbe18e21f, 
    0x3e02d0bc, 0x3d93c4ab, 0xbd06d9f2, 0x3e818518, 0x3c64e878, 0xbe7a63c6, 0x3d5465c3, 0xbdc1c971, 
    0xbe745162, 0x3e3c846a, 0xbe8f9493, 0xbe801ed0, 0x3e895d1c, 0x3dd71b99, 0xbde0876b, 0xbe64fd1f, 
    0xbe502de1, 0x3e84c015, 0x3e95751b, 0x3e446224, 0x3e638424, 0x3d832835, 0x3d120334, 0xbdc0c816, 
    0x3e080d43, 0xbdbc87b7, 0xbd799325, 0x3e6704a8, 0xbd88bff1, 0x3e162ec9, 0xbd830849, 0x3f0bcf4e, 
    0xbcd31be4, 0xbed6fe6a, 0xbe8e0d84, 0x3deaded5, 0x3ddd3539, 0xbc960ec5, 0xbda282b2, 0x3d1e4a49, 
    0x3de92c67, 0xbd10b1be, 0x3d15be53, 0xbd834e4d, 0xbe5558dc, 0xbe2a447a, 0x3c9941f7, 0x3e86782d, 
    0xbcdd773a, 0xbead6c81, 0xbd01bccd, 0x3d0dd28b, 0x3e2fc3ff, 0x3d936aaf, 0x3d717bbb, 0xbdff3174, 
    0xbcf90d1b, 0xbd758b7d, 0x3cb52280, 0x3e556bef, 0xbe80b5d5, 0xbe2bbf0f, 0xbe091cdc, 0x3e1cc94e, 
    0x3db4e147, 0xbe4e3065, 0x3b2840cb, 0xbd122581, 0x3e4e143f, 0xbf043239, 0xbd14e0db, 0x3e14142d, 
    0x3e1a3271, 0x3e16e5d1, 0xbe38449c, 0x3ee45ba9, 0xbe0c2284, 0xbc7885ff, 0x3e583ecf, 0x3da6905f, 
    0xbea4acbe, 0xbe9283d0, 0x3e7ad22c, 0x3e8468e6, 0x3d8c2863, 0xbe57296f, 0x3c9d0191, 0xbdab3750, 
    0xbd6e3a01, 0x3e1884e3, 0xbcc5010b, 0x3df916e8, 0xbe726189, 0xbdf4ad6e, 0x3dafbd0d, 0x3dbf5c80, 
    0xbe5dff0b, 0xbe34f0e9, 0xbd1b2f34, 0xbda2407c, 0xbe92fc0f, 0x3c2e467a, 0x3cbb338a, 0x3e19ff1d, 
    0xbd1638df, 0xbb0d9491, 0x3d8c0cbf, 0xbcdcac39, 0xbd8844ad, 0xbe3d4c4e, 0x3cc0c214, 0xbe182d52, 
    0xbcd4cb7e, 0x3c9238d8, 0x3e43a196, 0xbd2a3bc7, 0xbe6b37df, 0x3de2f926, 0x3d85257d, 0xbcf3cb08, 
    0x3b0183ec, 0xbde582d7, 0xbd4c0bd9, 0xbe13b014, 0xbdd770a9, 0xbd54d9a6, 0xbd372b2c, 0x3c03903b, 
    0x3e1280e6, 0xbde7ffd6, 0xbe2bd47b, 0xbd9f3421, 0x3e1390ee, 0xbc042582, 0x3d88a390, 0xbcfe436b, 
    0x3e7991de, 0xbe1994e9, 0xbbf8978b, 0x3e06c8da, 0xbd32d8af, 0x3e6165f1, 0x3dd33705, 0x3e3210d5, 
    0x3dd8250a, 0xbd748640, 0xbda16896, 0x3dc36b08, 0xbadea88a, 0x3e485f72, 0x3e07b1d6, 0xbae6eb49, 
    0x3eec2d26, 0xbe0e79e5, 0x3c756f3b, 0x3e53da2b, 0xbdcfcf5e, 0x3dab303d, 0xbd12b49a, 0x3ebf58ab, 
    0x3c91600f, 0x3dec83b0, 0xbe2e409b, 0x3e70f928, 0x3e2c6943, 0x3e8f28b5, 0x3d81a8d6, 0x3de4ba7f, 
    0xbdf14d4d, 0x3df8588a, 0xbd944cbb, 0xbd2d72e2, 0xbd85049e, 0x3e0c3ccf, 0x3e7f5079, 0xbe1d5c6b, 
    0xbc0469bf, 0x3c757804, 0xbf086923, 0xbe4b633a, 0x3ead977b, 0x3e1832cb, 0x3ca90c9d, 0x3e908b23, 
    0x3e3d1ceb, 0x3dde16be, 0xbd5f0ae9, 0xbb01e5fb, 0xbcb1e69f, 0xbde25c29, 0x3ea9f9da, 0xbcb08f34, 
    0xbdb64663, 0x3dda093c, 0xbe85149a, 0xbe96a69e, 0x3eb88b54, 0xbd9c77d0, 0xbd09c82b, 0x3e053238, 
    0x3e79d9a5, 0x3ca35054, 0x3cf772fc, 0xbde476eb, 0x3e7a0375, 0x3dcd98f6, 0x3ee85baf, 0xbd3efc67, 
    0xbe26cd3d, 0x3ead2f64, 0x3e0b835d, 0xbe26b1ec, 0x3ecbf135, 0x3e93ea5e, 0xbd8cbeec, 0xbd936420, 
    0x3cb8fefb, 0xbe93564d, 0xbd35ec4e, 0xbe9f9d0b, 0x3ddb957a, 0xbdb8a590, 0x3cb491c4, 0xbdea18d3, 
    0x3e09119d, 0x3ec0872f, 0xbea460a9, 0xbd5bcaec, 0x3c38c89e, 0x3e7ce63e, 0x3d752eb3, 0x3de55f46, 
    0x3cd89824, 0xb862757c, 0xbe1fb26d, 0xbe086c9d, 0xbc4052fb, 0xbb0f1bce, 0x3d1f962e, 0x3e512c81, 
    0x3da30bc3, 0xbddb1746, 0xbe1d19ac, 0x3c80ac3f, 0xbe8cacae, 0xbd9666b7, 0xbd9a6301, 0xbe15cffd, 
    0x3e26dca6, 0xbe61e190, 0xbdaee538, 0x3e5eae8a, 0xbe2da103, 0x3d95f171, 0x3eabfdea, 0x3f08e020, 
    0xbe18d181, 0xbef56498, 0xbec178a0, 0x3d7bf58d, 0xbedc6962, 0xbe3378c5, 0xbe2ac457, 0x3d347bed, 
    0xbd1644e7, 0x3cc3d700, 0x3d6f188f, 0x3d9af29a, 0x3d6aae69, 0xbc8d736a, 0x3d55911f, 0xbb3c750a, 
    0x3dc90fae, 0xbe8157fd, 0x3d9713a8, 0xbdad3f22, 0xbe1cb9af, 0xbe076991, 0xbe632fd8, 0x3d097d10, 
    0x3d305451, 0x3db4d2bf, 0xbdc84d3b, 0x3d15f4bc, 0xbd7640a7, 0xbd4932d1, 0x3ddf43f9, 0xbe566780, 
    0xbaa88b95, 0xbd6597da, 0xbb9ba669, 0x3d6d0c79, 0xbe14d5f0, 0xbd9b2a81, 0xbe66c57c, 0x3d3be979, 
    0xbdab9d77, 0xbd2a2331, 0xbda0ad8d, 0xbc6ed0e6, 0xbd7707b1, 0xbd1eedcf, 0x3d1e671e, 0xbe9cbb84, 
    0xbcb94278, 0x3d879193, 0xbd657173, 0xbca911c0, 0xbe52b61b, 0x3e22e67b, 0x3e8b45b0, 0xbe2fbc18, 
    0xbe0e9e56, 0x3e18d754, 0xbd8a3cb5, 0xbe98b9f4, 0x3e32bba2, 0xbe4b7bbd, 0xbe9fcfa8, 0x3da581b1, 
    0xbe386daa, 0xbd7b4547, 0xbe69c98f, 0xbd29b4e1, 0x3dd5a81d, 0x3d8b61e1, 0xbd2724cb, 0x3d6b640c, 
    0xbeab8f6e, 0x3e1a3294, 0xbd81b9d0, 0xbdda7f4e, 0xbced7a1c, 0xbde7f9e5, 0xbd6ae2ce, 0x3d577d8c, 
    0xbe97333c, 0xbb902a03, 0xbe79ae6c, 0xbdb04f60, 0x3dae12df, 0xbdb9077d, 0xbe6170bd, 0x3d894ca1, 
    0xbec1d8e4, 0x3c341043, 0xbe8cb6ed, 0x3d725012, 0xbdcf4cf4, 0xbda2b357, 0xbc587daf, 0x3d034c5e, 
    0xbd039e91, 0x3de5384f, 0x3d410ef4, 0xbe7de0ff, 0x3bb2ee25, 0xbcfcb5fe, 0xbc558514, 0x3d94eb2c, 
    0x3d197386, 0xbe1e0d62, 0xbd72403c, 0x3de0f163, 0xbe94b863, 0x3db20967, 0xbecea9dd, 0xbad25ea3, 
    0xbdeccbf2, 0x3e8358b0, 0xbe8c2b2d, 0xbb89c3f5, 0x3e7022d7, 0xbe86755c, 0x3d13484c, 0x3d2a4a79, 
    0xbce0a51d, 0xbe04d77a, 0xbdb1e80d, 0x3dfc566f, 0x3e430538, 0x3ccb3b9f, 0xbe99ea79, 0x3ca6b4f2, 
    0xbe1ab83c, 0xbdbd090e, 0xbe29694a, 0x3e0b98de, 0x3b6e5506, 0xbf155732, 0x3d196ed9, 0xbe236975, 
    0xbe6a9822, 0xbe325022, 0x3e3ee5b5, 0xbe4ceefe, 0x3e71d17d, 0xbdefbf09, 0x3aa5a7a0, 0xbde91d67, 
    0xbcbc7cb0, 0xbe528a2c, 0xbe481162, 0xbd48c5c1, 0xbdf5622b, 0xbecf77b3, 0x3dfda3d7, 0xbe881046, 
    0xbdb46e5d, 0xbefa93c5, 0x3c75d7fa, 0x3e54b47c, 0x3de427df, 0xbe8cf957, 0xbdaaee71, 0x3ec34ab7, 
    0x3b20800c, 0xbd107885, 0xbe932da3, 0x3d3086d6, 0xbe35e6fb, 0xbe7b05f0, 0xbe0ba6dd, 0xbe2376e6, 
    0xbe97b2df, 0xbdf48341, 0x3d3efcf6, 0xbe99d4e8, 0x3deffc74, 0xbe053152, 0x3d1ddbe5, 0x3e4c7bbc, 
    0x3dff3bff, 0x3e0f1e89, 0xbe1d8176, 0xbe00bea9, 0xbdc8c608, 0xbd983970, 0x3cbe2bbd, 0xbdb8bfe8, 
    0xbe4a308e, 0xbe3f7e36, 0x3e280eef, 0x3e023950, 0x3de3b790, 0xbe85789c, 0x3eceb93b, 0x3eb3f65a, 
    0x3ebe188d, 0x3d421d86, 0xbe7d4a15, 0x3d840c44, 0x3dc1fa2c, 0xffffce1e, 0x00000004, 0x00003000, 
    0x3eb481ff, 0xbec2fded, 0x3f0193e3, 0xbdb61592, 0x3f20ac0f, 0xbe309b65, 0xbe257009, 0x3ef9a460, 
    0x3f84c5b3, 0xbe9109a0, 0xbe6eee6d, 0xbea59d3c, 0xbe850c86, 0xbd60ec66, 0xbe67d066, 0xbe94feae, 
    0x3fd062b7, 0xbdaee5a4, 0x3dd1df4b, 0xbed3ea49, 0x3d4be7c5, 0x3ca96b5f, 0x3ee46cc0, 0x3e7cdeab, 
    0x3d5cc8eb, 0x3e764173, 0xbe9920ed, 0xbdcb9490, 0xbe790939, 0x3c389b58, 0xbc5d58b2, 0x3dc236d9, 
    0x3e32abf0, 0xbe819deb, 0x3df324e0, 0x3c5e1948, 0x3f67dcdb, 0xbd1fd153, 0x3bed492b, 0x3f018584, 
    0x3e51c0a7, 0x3ef84bc5, 0x3edea295, 0xbdc6d90e, 0xbe796f66, 0x3d3b3eec, 0xbd872253, 0xbce270d5, 
    0x3ec2297c, 0x3f8292c1, 0xbe49875f, 0xbed27aea, 0x3d9b6010, 0x3ee8ea68, 0xbe20f85b, 0x3c7332a8, 
    0xbdd8b480, 0x3c8ee519, 0x3e323327, 0xbe67d627, 0xbe0464e6, 0xbb605835, 0x3e330e58, 0x3e93d83a, 
    0x3d356e63, 0x3cec77bf, 0x3f381322, 0xbbb50622, 0x3e53e5d6, 0xbe291a83, 0xbc91a311, 0x3e600f94, 
    0x3f5f2e1e, 0x3e177b28, 0xbe95eaa5, 0xbe091781, 0xbd3f5321, 0xbecc9354, 0xbf439098, 0x3e10c647, 
    0x3fc64f60, 0x3f51cfb3, 0xbe4190c7, 0xbe1ef8f2, 0x3e250c90, 0xbe14d5e4, 0x3f9c689f, 0xbce9808c, 
    0x3e099eac, 0xbde1f9cb, 0xbe114cc1, 0xbe14fc87, 0xbef29cdc, 0x3e899f50, 0x3ce31fd7, 0x3e4c4494, 
    0xbda4700b, 0x3d5463f1, 0x3cf84038, 0x3e724c52, 0xbd80d731, 0xbdbfedef, 0xbe178727, 0x3eb34c25, 
    0xbdd27606, 0x3e4c21fa, 0x3f8a9593, 0xbe50de77, 0x3dee1d5a, 0xbd2908f0, 0xbe6e1d5a, 0x3d8edbcc, 
    0x3e9a716d, 0x3d82bc99, 0xbd424333, 0xbe609e4b, 0x3d04436c, 0x3f5f1d12, 0xbea72123, 0x3df487af, 
    0x3d9b8a58, 0xbe04f47a, 0x3f15b25b, 0xbc41c8ca, 0x3e9eaaec, 0xbd8e44b9, 0xbd8c63b2, 0xba72ce15, 
    0xbdf8581f, 0xbe60a61d, 0x3f10b3d1, 0x3d83d2f7, 0xbd9e6be3, 0x3d64f970, 0x3da9c7ea, 0x3e8f94b4, 
    0xbe85e22b, 0x3ec5780f, 0x3f7fd105, 0x3d48fc08, 0x3e1b7736, 0x3d0ff388, 0xbdbd4f54, 0x3db75f1c, 
    0x3cd24892, 0x3d796575, 0xbdbfd5eb, 0xbdec8e39, 0xbe0e624d, 0x3ee5c59c, 0xbe7bdb1c, 0x3ec29c4a, 
    0x3c42cafe, 0xbdceb4f2, 0x3f19ea6d, 0xbc0d12c6, 0x3e644f32, 0x3bedfb90, 0xbe38e929, 0xbdd2d66f, 
    0xbd6d5408, 0xbe913503, 0x3f0a2342, 0x3db1fb08, 0xbcb6ffdf, 0xbd262641, 0x3d860e0f, 0x3df32322, 
    0xbe227929, 0x3e8310b2, 0x3f8e13c3, 0xbd72b7fa, 0x3d62b4f0, 0xbe4a5287, 0xbdbcd86d, 0x3d123077, 
    0x3eaa5b03, 0xbddd347c, 0xbbeebd17, 0xbd7667fb, 0x3dcfe1d1, 0x3f3cdff6, 0xbdf82c19, 0x3e81c108, 
    0xbd6db820, 0xbe0d94e0, 0x3f38e86a, 0x3de1e2a3, 0x3eae7264, 0xbdd22ba9, 0xbe1220be, 0x3dd6ae85, 
    0x3ec91eed, 0x3f1d6244, 0x3c83d068, 0xbd89cdb6, 0xbf1e83f9, 0xbef044c7, 0xbd8aceca, 0xbe52090f, 
    0xbc53cdd7, 0x3e14721d, 0x3d66d5b6, 0xbd4bf304, 0x3ee809d6, 0xbce8d862, 0x3dc9d8a8, 0x3f6b22f7, 
    0x3d3b3a5b, 0xbe808d28, 0x3e8ae129, 0x3b65fdae, 0x3deaa3f4, 0xbe9434b5, 0xbdb59681, 0xbe52a8d0, 
    0x3dd8c250, 0xbe0b4ec5, 0x3e48a3af, 0xbe511780, 0x3e5c9133, 0xbe2c1215, 0x3e78ded5, 0xbdeb680f, 
    0x3e1f8129, 0x3f9551fa, 0xbf07a31d, 0xbe5fb238, 0x3e12a4af, 0xbe3893e8, 0x3e582de7, 0xbc7c718b, 
    0x3e080618, 0xbccd8cec, 0xbdfa90d2, 0x3db922a5, 0x3ec152ea, 0xbdbd57d1, 0xbd32fe71, 0x3f10d19a, 
    0x3e3b083d, 0x3e7847c7, 0x3d8f3919, 0x3dda0b06, 0x3e8ad679, 0xbe219ad8, 0xbd736162, 0xbea1339d, 
    0x3d91c1c9, 0x3e868581, 0x3dac0b81, 0x3e7fcf38, 0x3a0adb4b, 0xbe6f77b4, 0xbc5c2f13, 0x3c8248ef, 
    0xbdd224b4, 0x3e70ca6f, 0xbe7895a1, 0x3e7a060f, 0x3e3fa541, 0xbea6ff05, 0x3c249bab, 0xbd9e647f, 
    0xbd935d51, 0xbd3f65a8, 0x3bd5aa34, 0xbd0c35ff, 0x3bdbfa2f, 0xbd485e17, 0x3e267e61, 0x3f562326, 
    0xbe36d320, 0x3bf7f24b, 0x3e2cf4c3, 0x3e0d5f2c, 0x3e95c597, 0xbea9c07a, 0x3eb6102b, 0xbcabdb80, 
    0xbd3440b0, 0x3dc0fa21, 0xbdea1c6b, 0x3efb96fa, 0x3eac5e62, 0x3f148875, 0x3dd175e6, 0xbd2684fd, 
    0xbee1d236, 0x3f1523c4, 0xbe3d0bef, 0x3e89be11, 0xbe11ca04, 0xbd35b4b7, 0xbb49a189, 0xbe243cb3, 
    0x3d4804ff, 0x3ef0633d, 0x3e996dba, 0xbdf41624, 0x3f2894b8, 0x3e96f702, 0xbede50d3, 0xbd9328f6, 
    0xbe5fcd9b, 0x3e3ebafe, 0x3e188aaf, 0xbdda71c3, 0xbea0fa11, 0x3d88cd7f, 0x3e9f9d00, 0xbe8dda27, 
    0x3d88f494, 0xbe1b3829, 0x3f1564f0, 0x3e04091e, 0x3f7a196c, 0x3c836c12, 0x3f1bcba7, 0x3e358d76, 
    0xbe8cce33, 0x3f259383, 0xbe7dc210, 0xbd0e0e05, 0x3bd8fdf3, 0xbca5d118, 0xbe877288, 0xbecae0e6, 
    0xbe3bb1f1, 0x3ecd22bc, 0x3f1794ab, 0xbeb7c8a5, 0x3e3fbf1e, 0xbd095a0e, 0xbe523926, 0xbde29fed, 
    0x3cb33e6d, 0xbdb66a49, 0x3df937f0, 0xbe672f87, 0xbed12e1d, 0x3d57c545, 0x3e37f877, 0xbe38fde3, 
    0x3d4d3ded, 0xbe8372f4, 0x3efae97f, 0xbd69d1d3, 0x3f363fa1, 0xbe1466cf, 0x3d3d9bfd, 0x3c8b7f3b, 
    0xbe511a2a, 0x3e864b5e, 0xbea6b726, 0x3e94e0b7, 0xbe9112af, 0x3e828e2b, 0xbcf26bca, 0xbe39eaf2, 
    0x3df3ed1a, 0x3e9b373e, 0x3ec0f2be, 0xbd894236, 0x3f17b8c3, 0x3c83d91a, 0xbed154ac, 0xbe50387b, 
    0x3db60ba8, 0x3f11d479, 0x3dc07deb, 0xbf16e25d, 0xbe96510d, 0x3c967380, 0x3e7ea1ab, 0xbec8dc56, 
    0x3e0f920a, 0xbeeb7907, 0x3e658ace, 0x3c8c0ef7, 0x3ec69be5, 0xbe81b7e6, 0x3f8a56b2, 0xbd9b2e05, 
    0x3d9c6241, 0xbd408729, 0xbe7ac961, 0x3e53f010, 0x3ee484de, 0xbd35e44e, 0x3d290e24, 0x3df49df8, 
    0x3f8bc9ff, 0x3f30f0a3, 0x3f3f2338, 0xbeb22d66, 0x3e471b5d, 0xbd05384f, 0xbe8b7550, 0xbd697215, 
    0xbe0f6832, 0x3e4beca6, 0xbcdb9f0a, 0xbcaaee79, 0xbe3bd63f, 0xb8007325, 0x3e7e7e2d, 0xbed701aa, 
    0xbd5a7fb4, 0xbe79a8b8, 0x3f3bbed5, 0xbe288062, 0x3f02bbcd, 0xbccdc251, 0xbec784a6, 0xbe31d566, 
    0x3c1f0449, 0xbcd86cf9, 0xbe3fa1bf, 0x3e70a861, 0x3e4ebe77, 0xbcd146ec, 0x3d88b317, 0x3ea708e6, 
    0x3fb1e9d5, 0x3f38ac53, 0x3f3148db, 0xbeac4008, 0x3e71b586, 0x3c8dfdf2, 0xbea6c4da, 0x39cfcc9f, 
    0xbea7d2d7, 0x3f64e4fa, 0xbe5b62df, 0xbe69f833, 0xbc858692, 0x3d3f5641, 0x3e0ed940, 0xbe88a4aa, 
    0x3dd791ef, 0x3e15df00, 0x3f2d8fc6, 0xbdcccbe2, 0x3f04b598, 0xbd8044a3, 0xbf0e3c4e, 0xbe137ba9, 
    0x3e1b8f86, 0x3cb949ee, 0xbe97710f, 0x3e14eb95, 0xbcc74af8, 0x3e0ec057, 0xbdab667b, 0x3eb07499, 
    0x3fad8c7c, 0x3f5d68c0, 0x3f169ccc, 0xbe3b17b3, 0x3e03709c, 0xbb8d8ebd, 0xbece89f0, 0x3de58c7a, 
    0xbe32aa39, 0x3e8372e4, 0xbe693714, 0xbe861636, 0x3d6c69f2, 0xbd57faf4, 0xbe0a5faa, 0xbe87a3d8, 
    0x3cfcb0ae, 0x3e0b15ec, 0x3f6bbb89, 0xbdfe5ed7, 0x3f20eb7d, 0xbd4ec368, 0xbeb87828, 0xbdc3962d, 
    0xbb8a726d, 0x3e745fa3, 0xbd0b0136, 0x3cb93df8, 0x3e156eba, 0xbbacb046, 0xbccc5685, 0xbd22e554, 
    0x3ea99c1b, 0x3cdbdb24, 0x3cdebf58, 0xbe99ab7f, 0x3e46783a, 0x3dfd6149, 0xbf5e0447, 0x3e02eb56, 
    0xbf2300c2, 0x3eae5d70, 0x3f39ac3a, 0x3e1157fb, 0xbe126d3b, 0x3e62553f, 0x3ee6e765, 0xbe1332d0, 
    0x3ce32066, 0x3e856468, 0xbe60e23e, 0xbdc092d0, 0x3f176e52, 0x3d9a4e7f, 0x3e3e1463, 0x3db0d161, 
    0xbcd75999, 0x3df80e69, 0xbdb9652a, 0x3e24487d, 0x3e10911c, 0xbc005d4b, 0x3cdea708, 0x3dda1127, 
    0x3ea727ba, 0xbe07af31, 0x3e4a74f7, 0xbf02cc55, 0x3ee775b9, 0x3d88e392, 0xbe923478, 0xbef030cd, 
    0xbf48ce81, 0x3e99f717, 0x3f7c7395, 0xbdc0d75f, 0xbe0e3d79, 0x3e5da1aa, 0x3ece581b, 0xbd623716, 
    0xbdb86749, 0x3e8dc34f, 0xbe773f02, 0xbeb33bd2, 0x3e00b676, 0x3d6d55aa, 0x3f777cf5, 0x3d92018f, 
    0x3e0e4285, 0x3e8a98c5, 0xbe4178df, 0x3f0e70af, 0xbe884d46, 0x3f6eeb75, 0xbc974d3f, 0xbdcc2764, 
    0x3e4cc214, 0xbec0e680, 0x3e03b63a, 0xbe775c9b, 0x3ecc44ae, 0x3eb0524a, 0xbec29218, 0xbf192f8a, 
    0xbf09345e, 0x3e5bb08d, 0x3f6e1e55, 0xbe9edf58, 0xbe313197, 0x3d99b92a, 0x3e24677c, 0xbe43619f, 
    0xbd3507c8, 0xbe04a25d, 0xbd8bb05f, 0xbc28d4db, 0x3d1ede60, 0xbe1d5742, 0x3fa99383, 0x3d5474d3, 
    0xbcd0eda6, 0xbe59cf6e, 0xbe30c88e, 0xbe7ec548, 0x3e5d316e, 0xbe8cb21c, 0xbb1fc215, 0x3e43f28d, 
    0x3d8867f7, 0xbc58c28c, 0xbe339079, 0x3d77501a, 0x3e384ca5, 0x3ea08122, 0x3c24a7be, 0x3f09ff0d, 
    0x3f33e7cd, 0x3ece6e4b, 0x3e14e583, 0xbd87980a, 0x3f2e692a, 0xbde24ffe, 0x3ef34ae4, 0x3c850863, 
    0xbde51d7b, 0xbd09c13b, 0x3d1e4f2f, 0xbdef63b7, 0x3e95561a, 0xbee67cfb, 0x3da762b3, 0xbb59845a, 
    0x3e48458f, 0xbe0509ff, 0x3cd92033, 0x3c4e2c21, 0x3d5340d4, 0xbf056246, 0x3c4d1a18, 0xbd5a427e, 
    0xbea99495, 0x3e916de9, 0x3c351562, 0xbe218cb4, 0x3e6bee66, 0x3b8e9a67, 0xbe3db093, 0x3c8082e2, 
    0x3f642433, 0xbed368c3, 0xbd51f968, 0xbe22ec2b, 0x3ec99f42, 0xbe1116e7, 0x3f2b6e73, 0xbe927f74, 
    0xbdee18ec, 0x3e841c5a, 0xbd98b578, 0xbdb0f530, 0xbcf7fe5a, 0xbd296ce0, 0xbd5b77dd, 0x3dea5824, 
    0xbeaf26d7, 0xbdabf62b, 0xbe05c507, 0x3daff9fa, 0x3ebb6f78, 0xbde938f3, 0x3d9264d1, 0x3d604383, 
    0x3ebc59fb, 0xbd000059, 0x3dac43be, 0xbc883c74, 0x3e52e5f6, 0x3e5aa6b7, 0xbead7b7f, 0x3ea301da, 
    0x3ef9cf44, 0x3dfdd2e0, 0xbe0caee6, 0x3e61cc9a, 0xbda1e389, 0xbe555362, 0x3ee5673a, 0xbde061d1, 
    0xbd69273a, 0x3ea9a0db, 0x3cd35dbb, 0x3ddbdea3, 0x3d8df97d, 0x3d8707ca, 0xbc1ccbce, 0xbdb31f6f, 
    0xbe7c0978, 0x3d18c3bc, 0x3e1bd865, 0xbd83fa86, 0xbe90dfd1, 0x3df8fb36, 0xbd5685c1, 0xbdcef534, 
    0x3de16b9f, 0x3dfa33da, 0x3e8d568f, 0x3cbf41b2, 0x3df99ad9, 0x3e9ac7e0, 0x3e025b6d, 0x3e83e802, 
    0xbea4cc89, 0x3e14d81f, 0x3cd93502, 0xbd896c92, 0x3e96b79a, 0x3df013bc, 0xbdf5066f, 0x3de2a02d, 
    0xbdf01a2f, 0xbf184736, 0x3e6d9710, 0x3db1fd7f, 0x3e56f3e3, 0x3de8416c, 0x3d8a0a92, 0x3c9aa0f8, 
    0xbda69f6c, 0x3dc5f2d0, 0x3ddff910, 0x3d2fb1c3, 0x3e1b7df7, 0x3a4e4439, 0xbe7fec7a, 0xbcaee91c, 
    0xbe04ac5b, 0x3e68f81b, 0x3ea3ec60, 0xbe356f41, 0x3e3a5a54, 0xbe0881af, 0x3c69ba40, 0x3dc93e6c, 
    0x3e5d7a9c, 0x3c766eff, 0xbea6ed34, 0xbe65b8ae, 0x3e57c488, 0x3e3163ad, 0x3ef9dff5, 0xbe980518, 
    0xbc08dd4f, 0x3e40ce9f, 0x3e4568d6, 0xbe26a8fd, 0x3dea9c1a, 0xbdedfc32, 0xbe4d592d, 0x3d5518ca, 
    0x3d8db48f, 0x3e151805, 0xbe306fa2, 0xbc4832bf, 0x3e5358e3, 0xbe13ed9a, 0xbe9b52b2, 0xbd595f62, 
    0xbe4d87bf, 0x3f0cc5f9, 0x3ecf535d, 0xbedf8bac, 0x3ea82f21, 0xbe8de04b, 0x3d59418a, 0xbdb4eaa3, 
    0x3dee9dd5, 0xbd9cc3a8, 0xbea246bc, 0xbe0106f3, 0xbe6a26fd, 0x3e67bae0, 0x3de70058, 0xbe3e4b08, 
    0x3da64bff, 0x3e3ed74f, 0x3e934770, 0xbe8138f0, 0x3dc61d14, 0xbd8b5daa, 0x3d9d598f, 0xbba2700b, 
    0xbd829270, 0x3e49db71, 0x3c82607d, 0xbdb94ce2, 0xbdd4088b, 0x3e050c1a, 0xbe209209, 0xbd202dfc, 
    0x3f69eb46, 0x3e9b3bac, 0x3efd02da, 0xbf2d43a0, 0x3e289a4a, 0xbe3338d4, 0xbf27e0dd, 0x3e25461b, 
    0xbed5a531, 0x3e210145, 0x3e40102a, 0xbe3468ce, 0xbef3e072, 0x3e21279a, 0x3de7ca6b, 0xbf083a0b, 
    0xbc8bb46c, 0x3bf27af3, 0x3dc992da, 0xbdffb10d, 0x3eb3f6f9, 0xbc8073d2, 0x3e06005e, 0x3c41778d, 
    0xbdd09b92, 0x3e4f6ccf, 0xbe56ee73, 0x3da2ba2b, 0x3ea69206, 0x3dfdd848, 0xbe8d2ead, 0x3e3f1106, 
    0xba9a74a2, 0x3e0751a0, 0x3e964c1e, 0xbf139443, 0x3efe2f99, 0xbd3813a1, 0xbf379414, 0xbd999920, 
    0xbec214ea, 0x3dbd8ecb, 0x3ec9d443, 0xbef27082, 0xbe016a55, 0x3e394eac, 0xbe1f0e7b, 0xbec04aba, 
    0xbd5985d0, 0xbddf1528, 0x3e0d0f08, 0xbe8ee866, 0x3e8e1e9e, 0x3d71e490, 0x3d2b59db, 0x3dca219e, 
    0x3e51e3a2, 0x3e51684e, 0xbea4acff, 0x3eaddd46, 0xbf1fd608, 0x3f0e233a, 0xbf081d52, 0x3d68bd6f, 
    0x3f21c9e3, 0x3e05737d, 0x3e834020, 0xbed957d0, 0x3e121e8f, 0x3bfd566c, 0xbf2d18fe, 0xbd5de48c, 
    0xbe43a0c1, 0x3e99a461, 0x3e4b274f, 0xbeea810c, 0xbdc5382f, 0x3e31ed3a, 0xbd8a4977, 0xbf0c78e3, 
    0xbde9343c, 0xbe1ec2f0, 0x3dec5212, 0xbe0a4eab, 0x3d11f8e7, 0xbe8a53dc, 0x3e3148f3, 0x3b48b8c7, 
    0xbd1c2403, 0xbe7418e0, 0x3edfc7f2, 0x3d416438, 0x3d229744, 0x3d852dcc, 0xbdc6bbdf, 0x3e289dd5, 
    0xbdcc169d, 0x3e03ac49, 0x3f81dbf2, 0x3d114604, 0x3ba0e11c, 0xbe6d5424, 0x3d9dd09f, 0xbd97dfda, 
    0x3f1e78df, 0x3c831984, 0xbce4b0e6, 0xbb79c28a, 0xbe283daa, 0x4015b9da, 0xbd6a4a66, 0x3d2b5e54, 
    0xbdeabd18, 0xbe12e0cf, 0xbdb4643a, 0xbcdb169c, 0xbe593b98, 0xbd6e35c5, 0x3d80c33d, 0x3d249de1, 
    0xbe3e1245, 0xbe1bf3c6, 0xbcb156f1, 0xbdba9bbc, 0xbd580f77, 0x3d5523c7, 0xbde5092a, 0x3e845026, 
    0x3d5493fd, 0x3d1fa127, 0x3f934033, 0x3d21f4c0, 0xbe2b9531, 0xbe7c679c, 0x3d88fce3, 0x3c111510, 
    0x3f4b5642, 0xbdcd2dd6, 0x3c995e95, 0xbd94e90a, 0xbe597adc, 0x402537c8, 0xbe2ceb31, 0x3dc68164, 
    0xbe609298, 0xbd5f1f5e, 0xbd09a120, 0x3c9e86f0, 0xbe8e101e, 0xbd08332e, 0x3d907520, 0xbe01e3e8, 
    0xbdb85237, 0xbcbacfb3, 0x3f4980da, 0xbdbb7646, 0xbdb5c02a, 0xbdc6184f, 0x3d4ec965, 0x3ef2bb4c, 
    0x3c180fbf, 0x3db44eab, 0x3f8fcc43, 0x3c99be7f, 0xbe0526ca, 0xbe181dee, 0x3e0bf19b, 0x3d213c25, 
    0x3f5cf2b6, 0xbd38e8cb, 0x3d7d2887, 0xbe62f084, 0xbde53392, 0x4021caeb, 0x3ea5647d, 0x3daaa142, 
    0x3e37ce6b, 0xbe150db9, 0x3dbd1ce7, 0xbb130d61, 0xbe1956d9, 0x3e43bfb5, 0x3cdee048, 0xbe7395d1, 
    0x3ec1b687, 0x3e04979c, 0xbe900c0d, 0xbdaee341, 0xbef33f16, 0xbe82e9da, 0xbe142583, 0xbe324d20, 
    0x3e9a3971, 0x3bf214e5, 0xbd52b00c, 0xbe1caadd, 0x3eb1bfe5, 0x3dd62de3, 0x3e356aad, 0x3eb326d6, 
    0x3d88d23e, 0x3e8cb0fd, 0x3d465787, 0x3da49a72, 0x3de61f20, 0x3da719ba, 0x3d49dd75, 0xbe09fd95, 
    0xbdd340ff, 0xbc890f08, 0x3d273637, 0xbe83b5d8, 0x3eba08b8, 0xbe6ec34d, 0x3f15e145, 0xbdca6843, 
    0x3eb24137, 0x3f92de47, 0xbf582a2e, 0xbe800041, 0xbe5c5c0b, 0xbe342e63, 0x3e85bde5, 0xbdd1a3aa, 
    0x3d8dec3f, 0xbe4587ac, 0x3c176036, 0x3e8c0c40, 0x3f1e19a3, 0xbeef0624, 0x3bcd0a69, 0x3e1a3cbf, 
    0x3df1bdc3, 0xbd611310, 0x3d97cafc, 0x3c961807, 0x3e49733f, 0xbe2867ec, 0xbe19ee50, 0xbe8b18eb, 
    0xbd8c0d65, 0x3ed6214f, 0x3e2160c2, 0x3ee60152, 0xbc311e05, 0xbda8d11f, 0x3e95e609, 0x3e1694b0, 
    0xbde23782, 0x3f509520, 0xbeddce02, 0x3e0acb62, 0x3e40ec30, 0xbe7ed71c, 0x3d8e0413, 0xbdb3c980, 
    0x3e1a3602, 0xbdea16e7, 0xbc2835cf, 0x3dad54fa, 0xbda024cb, 0xbe32ae9f, 0x3d9aa8b8, 0xbe8481b0, 
    0xbe071332, 0x3daf890d, 0x3ed861d4, 0x3e8c83b1, 0x3e2739f6, 0xbecc35ad, 0x3e380338, 0xbd1ac940, 
    0x3da533b2, 0x3f012d3a, 0xbd086022, 0x3f65074b, 0x3ec79bf8, 0x3ea27f80, 0x3d662b55, 0x3e0bb45e, 
    0xbe5c1465, 0xbee16036, 0x3eeab3bd, 0x3f5bb866, 0xbd9cecd0, 0x3f0f9da3, 0x3f0c13f6, 0x3c8644de, 
    0xbe4038e2, 0x3e17f741, 0x3f1a4371, 0xbe0f2b46, 0xbbdb6a9a, 0xbd83508a, 0xbeec961c, 0x3e38d762, 
    0x3ae6e4af, 0xbe5b63cc, 0xbe897486, 0xbdcc370b, 0xbdd8f0df, 0x3f511a1e, 0xbdc7c265, 0x3e870dd7, 
    0x3e08eed4, 0xbe44ab33, 0x3ebc008e, 0x3cee6c4a, 0x3ea55b39, 0xbdd770fe, 0x3d8a1dbc, 0xbcbc47a7, 
    0xbd81cbbd, 0xbe7008c6, 0x3eacc8d2, 0x3f5009f5, 0xbda2856a, 0x3f6f53c4, 0xbe1b3902, 0x3d588584, 
    0xbe90ac82, 0x3e16e6a2, 0x3f3796f8, 0x3e96a36c, 0x3e033b98, 0xbd7e4469, 0xbe6d7f7e, 0x3b5acee0, 
    0x3de1e0d5, 0xbd8e7189, 0xbe8bd125, 0xbeaf847a, 0xbd09a699, 0x3f1050c5, 0x3e155bee, 0x3e075b85, 
    0xbc3f1e87, 0xbde83a56, 0x3f0b0ad0, 0x3db4df25, 0x3ee173b4, 0xbdbffe9c, 0xbe132337, 0xbe433a21, 
    0xbe4b3903, 0xbf1a3acc, 0x3ec3c8d9, 0x3f0d30c1, 0xbe4c54b6, 0x3f430d10, 0xbe9c39f8, 0x3e165619, 
    0xbe44f70d, 0xbda9045c, 0x3ef66c0a, 0xbe3b7480, 0x3e5628a9, 0xbe5ee181, 0xbe7269c5, 0xbde69c3e, 
    0x3ceec227, 0xbca39add, 0xbd97102f, 0xbec92d68, 0xbdc6eadf, 0x3ee7748d, 0xbe46c815, 0x3be352c5, 
    0xbd30c010, 0xbdec326c, 0x3efddec9, 0x3ec96811, 0x3ecff4d2, 0xbeeabf41, 0xbed43400, 0x3da2a507, 
    0x3dac29a6, 0xbefa3886, 0x3f91e388, 0xbe2161a0, 0x3f197cfb, 0x3cfc9666, 0x3dda3779, 0x3e738be5, 
    0x3f5821de, 0x3f6949ac, 0x3ed23ac9, 0xbccece76, 0xbe59f385, 0xbe92567e, 0xbd9d7e43, 0xbf2dc73f, 
    0x3f7517c4, 0xbde57934, 0x3cd787c9, 0x3e3cdc9a, 0xbe699385, 0x3f3f7399, 0x3f0e8cb2, 0x3e76d142, 
    0xbdea3f27, 0xbefdbe08, 0x3eb37161, 0xbdb37fd0, 0x3e40e405, 0xbe42b393, 0xbe38ac58, 0xbe6ab1fb, 
    0x3c970470, 0xbeb2a5ce, 0x3edf025f, 0xbe853621, 0x3ea40f9d, 0x3e145d05, 0x3dc09f2d, 0x3ed3d13a, 
    0x3f64de53, 0x3f7c8b8f, 0x3e1b2777, 0xbdfa3a12, 0xbea86981, 0xbdbfb254, 0xbe050746, 0x3d4b329a, 
    0x3f25242b, 0x3f86ed82, 0xbe3d7b7b, 0xbe303cb0, 0xbe0829ff, 0x3f5060da, 0x3eb79f89, 0x3ea3fc2d, 
    0xbe31b9a0, 0xbd6b86ea, 0x3ea010ac, 0xbe866845, 0x3c9b6658, 0xbde425e3, 0xbda53697, 0x3cebf6cb, 
    0x3e5ae425, 0xbea8a3a6, 0x3fd8436f, 0xbeb4a64a, 0x3e3d3fec, 0x3d7d1302, 0x3da121bf, 0x3e77f75e, 
    0x3f8fdd6a, 0x3f5d00a8, 0x3d936389, 0xbdcdca63, 0xbe5e856c, 0xbeca246e, 0xbdeab7f1, 0x3d9a141a, 
    0x3f40f42b, 0x3f2fb723, 0x3deb8c49, 0xbe0bc0c3, 0xbd5cf7bf, 0x3f131edf, 0x3f248a86, 0x3f00baa6, 
    0xbe368d2c, 0xbe1e960c, 0x3f3b9adb, 0xbeaa8ae5, 0x3d9c4a2d, 0x3e27f499, 0xbe170cb6, 0xbe7aeeca, 
    0xbdca6032, 0x3f84028e, 0xbeba9060, 0x3e96a332, 0xbd94b997, 0xbdf889dc, 0x3e69f468, 0xbe72c112, 
    0x3d90aa84, 0x3d601e0d, 0xbddde02a, 0x3cc288d1, 0x3e9bb3d9, 0xbd4c85a7, 0x3e9420c6, 0x3f6dc4f4, 
    0xbef0bb78, 0x3dae5c19, 0x3e9dc737, 0xbdcb9e8a, 0x3eae6512, 0xbec21f2d, 0xbc9194a5, 0x3df1040b, 
    0xbda76bd4, 0xbdf6a390, 0x3de0fc1c, 0x3f1002ba, 0x3dda5e58, 0x3f3a6f71, 0x3e86572d, 0xbc6d9ec0, 
    0x3c886318, 0x3e853998, 0xbebb830a, 0xbe4cbf50, 0xbdcbbb8b, 0x3d4d1ab9, 0xbe208385, 0xbd5ad185, 
    0x3e2757a8, 0x3e1204b4, 0x3d84e5ba, 0xbda52e2b, 0xbe8b8ab6, 0x3ce39b22, 0x3e72cac2, 0x3f15ae88, 
    0xbe565387, 0xbe89922c, 0xbd99eb9e, 0x3caabfe3, 0x3e5f63fb, 0xbea32ad3, 0x3e7525c5, 0x3df1d2de, 
    0xbd687978, 0xbce6bccd, 0xbd87eaab, 0xbe341f58, 0x3e724c7e, 0x3e5aced6, 0x3dfb1629, 0x3c5689c7, 
    0x3ed11a7b, 0x3f6285f7, 0xbe5e5c95, 0xbd1039cb, 0xbe171983, 0xbf0908b0, 0x3dd18426, 0x3cb2db80, 
    0x3ddef49d, 0x3ea897ec, 0x3bf3323c, 0x3da6b91d, 0x3f2c64f4, 0xbe0e6678, 0x3e8357fa, 0x3f4f287b, 
    0x3e9a06ce, 0x3dc291b7, 0x3e6aee5d, 0xbed77a13, 0xbcf8cac6, 0xbe33a242, 0x3ead92c2, 0xbe1e628c, 
    0x3d2404d1, 0xbdab5dd7, 0x3e082d93, 0xbdaef88e, 0xbd86c1b7, 0xbcbe393c, 0x3f0a32c7, 0xbc8c8ca0, 
    0xbc3efe4d, 0xbe755f3a, 0xbd8661c1, 0x3d838d28, 0xbcc398dd, 0x3d7cf9cd, 0x3c141f5e, 0x3e4506cf, 
    0xbddda975, 0x3de9f9db, 0x3fb7fd97, 0x3d34587b, 0x3d9c0096, 0xbdc33f4d, 0x3c1e04aa, 0xbc3a29b2, 
    0x3ee249ce, 0xbda554d1, 0xbd329d2d, 0xbcbf0730, 0xbe344764, 0x3ff7652f, 0xbda16dc3, 0xbd1c6ed4, 
    0x3b621635, 0xbe18b94b, 0x3e451d38, 0xbc9261c4, 0xbd64640a, 0x3ce15ac0, 0x3c0a8793, 0x3de42f2a, 
    0xbd929c98, 0xbe62d7bb, 0xba82bd1d, 0x3d07b7b9, 0xbd9f10f9, 0x3be5caed, 0xbd225c4a, 0x3ebe53d8, 
    0xbd988756, 0x3dbe7c1a, 0x3fb5abbc, 0x3d5949a4, 0xbd3771bd, 0xbdfe5456, 0x3bce7bdb, 0x3d5f01a2, 
    0x3f140639, 0xbe6170cd, 0xbd30ade3, 0xbde8c36c, 0xbe1bcf1d, 0x40004cb9, 0xbe275a7e, 0xbe099edd, 
    0xbb4976ac, 0xbd8ee25f, 0x3e7fa506, 0xbd0bf96d, 0xbe37d736, 0xbce02978, 0x3d42e390, 0xbe605b3a, 
    0xbc8ea63d, 0xbd9dd730, 0xbd14e459, 0xbca8e39c, 0xbdd24952, 0x3c458e0e, 0x3d859689, 0x3e4825df, 
    0xbd52e832, 0x3d9f0d18, 0x3fa2b820, 0x3d50deca, 0xbcff3d60, 0xbd772ebc, 0x3d7606c2, 0x3b96ca86, 
    0x3f1fbc46, 0xbe064c1b, 0x3c461341, 0xbeb04e3c, 0xbd17d292, 0x40020872, 0x3e3ed3c8, 0xbd467ea2, 
    0xbde71ecb, 0xbde6f818, 0x3ea696c1, 0xbc985cb6, 0xbb85aafa, 0xbbed98ae, 0xbd183e75, 0xbda6c13b, 
    0x3e84ff05, 0x3f3701bc, 0xbef519e1, 0x3f20eb3c, 0xbe762550, 0x3c94a15e, 0x3ebc81ab, 0xbe45030d, 
    0x3ea0139d, 0xbe1bd2ee, 0xbd181861, 0x3edcdc1d, 0x3e8f0734, 0xbd27ba0b, 0xbe903a91, 0xbcc54b10, 
    0x3d52432b, 0x3e05b23c, 0x3eece0d9, 0x3dda5955, 0x3e8e575c, 0xbd6eeed9, 0xbd8d1d1b, 0x3eb1a824, 
    0xbe232f4b, 0xbd59f543, 0x3c7cd8ba, 0x3f151934, 0x3f02db9f, 0x3e448801, 0x3ee56cce, 0xbe29c407, 
    0x3d943cd8, 0x3df45702, 0xbebd56ab, 0xbd901831, 0xbd8689ac, 0xbc0536f9, 0x3e0752eb, 0xbe108428, 
    0x3ea640f5, 0x3db19e9a, 0x3db16461, 0x3c8d0132, 0xbec3414c, 0xbe4d6269, 0x3e824a44, 0x3d1cb88d, 
    0x3d45637d, 0x3e08ff5b, 0x3e88389d, 0x3db315d4, 0xbd060a4e, 0xbdcc65b3, 0xbd63bb58, 0x3ce38d8c, 
    0x3d86a93a, 0x3e859b10, 0xbd99f302, 0xbde94b75, 0x3e3ed699, 0xbd22799d, 0xbddf7665, 0x3d1e7870, 
    0x3c2aae02, 0x3f5062a1, 0xbe610933, 0x3f04328f, 0xbdf93274, 0xbe8732d9, 0x3f08354b, 0xbe407e59, 
    0x3d5ed3fb, 0xbe6cc5b3, 0xbdf8e7c9, 0x3eef9701, 0x3efaf51f, 0xbe687394, 0xbc5ad2f1, 0xbdc2ffc4, 
    0xbe882850, 0x3b532bf3, 0x3ebd91c9, 0x3ea99632, 0x3dd7931c, 0xbea2c13c, 0x3eb7c82a, 0x3e2d87f6, 
    0x3e2b4140, 0x3e3eb73b, 0x3abce95e, 0x3f3b02f1, 0x3e3a0bf8, 0x3da95531, 0x3eb7f8c8, 0x3deaf692, 
    0xbe25f59f, 0xbe60d3e4, 0x3ec30d16, 0x3f5b4f28, 0xbe19adbe, 0x3fb6832e, 0x3e22024a, 0x3e7ee3df, 
    0xbe2a7987, 0x3d1e8865, 0x3f00432b, 0xbb2fd0b7, 0x3e138ac7, 0x3c1b5d72, 0xbf2e6a21, 0x3e7ee1b1, 
    0x3e72050e, 0xbe4f9e1f, 0xbd825695, 0xbe26a1f3, 0xbc1714b4, 0x3ed36414, 0xbe834098, 0xbc53adc5, 
    0x3d6d5ab2, 0xbd09fe09, 0x3e9a2048, 0xbcdcd8a4, 0xbe796412, 0xbd4933f8, 0xbc1a78d9, 0x3cb05aa8, 
    0xbd8bd90b, 0xbf2a791a, 0x3e6c0e58, 0x3f0ec6f3, 0xbd57d817, 0x3f91d15c, 0xbdfcc056, 0x3e649ca9, 
    0xbe89c69d, 0x3e685b3b, 0x3f219333, 0x3df152b8, 0xbb706ec8, 0xbe5c6a48, 0xbe92b27a, 0x3ddc1a59, 
    0xbe08e33d, 0x3db1fbec, 0xbdf90228, 0xbecef66e, 0xbc4472e0, 0x3f34f574, 0xbe0d91a9, 0x3df92a48, 
    0x3e096fa8, 0xbe6fbbf0, 0x3ef90083, 0x3dd47ab1, 0x3e3aa5d6, 0xbc41b312, 0x3bb178b9, 0xbdf6d141, 
    0xbe0503f0, 0xbf4f2382, 0x3ec90384, 0x3f26cb2e, 0xbde784ce, 0x3fa7f05d, 0x3f2ea0c0, 0x3e24018b, 
    0xbe3db68b, 0x3caf6d9d, 0x3f1bcc64, 0xbdd7546f, 0xbe25845d, 0xbd96d5e0, 0xbe75c814, 0xbce49161, 
    0x3d1d9a58, 0xbdc61d3a, 0xbe67e55d, 0xbed031b6, 0xbdf58a18, 0x3f35147f, 0xbd26ed15, 0x3e60ede0, 
    0x3e4881eb, 0x3d003c64, 0x3e94d096, 0x3eb2fba5, 0x3ed79916, 0xbe9f602f, 0xbdec2b2b, 0xbd49e122, 
    0xbec50e70, 0xbd80f621, 0xbdc4c488, 0x3f162005, 0xbdfcb8cd, 0x3f7cc0b3, 0xbdcb432d, 0xbd894191, 
    0xbecf790f, 0x3b2fbbc3, 0xbddb6776, 0x3b996dfd, 0x3e6e2c42, 0xbe5a791c, 0xbe9d2f7e, 0x3e16d77f, 
    0x3de33a4c, 0xbf158658, 0xbea2b2fb, 0xbe067417, 0xbe877a42, 0xbdb79580, 0x3ee7395a, 0xbd6acc2b, 
    0xbb68ecc1, 0xbe013226, 0x3e85444d, 0xbdc1f75d, 0x3ed3be81, 0xbe33e7ed, 0x3defc122, 0x3d689dba, 
    0xbe85566a, 0x3c98d24e, 0xbe7b761e, 0x3e414b2b, 0xbd2a34ef, 0x3f11c69d, 0xbdd76499, 0xbe2aa114, 
    0xbef64cbd, 0x3e39f5fb, 0xbe1136e9, 0xbdba0462, 0x3e4fc068, 0xbe620efc, 0xbe936a97, 0x3c8ffc93, 
    0x3d4edfb2, 0xbf38081d, 0xbe08b384, 0xbe9b2ade, 0xbe88ba63, 0xbd3c9ce8, 0x3e7c9c76, 0xbe0b46a0, 
    0x3cb90375, 0xba188f2c, 0x3eab3572, 0x3bcd70c2, 0x3f0780ad, 0xbe1f5325, 0xbd9d2191, 0x3d0b2d49, 
    0xbeb1599c, 0x3e5dc494, 0xbe337622, 0x3f416af0, 0xbe169a12, 0x3ed37fe0, 0xbe16f4c0, 0xbda2697e, 
    0xbeaeda3b, 0xbd132453, 0xbdcc38d8, 0x3d9b2fa9, 0x3e034406, 0xbd7e6b54, 0xbeb0277d, 0xbd992cda, 
    0x3e575b8a, 0xbf20d0e8, 0xbe96c5b4, 0xbf2d93ba, 0xbe440d51, 0xbde1fcca, 0x3e9b62ae, 0xbdf4104d, 
    0x3db98753, 0x3d0d8260, 0x3d733fa5, 0x3e4527be, 0x3f2256ba, 0xbe5f1f72, 0xbd2d776e, 0xbde98acd, 
    0xbe2f05fd, 0x3d250ee0, 0xbe9b0627, 0x3e832184, 0x3dffbabc, 0xbe164089, 0x3efb7375, 0x3c98a3b6, 
    0x3e99bf01, 0x3e31109b, 0x3e2d41c0, 0x3e07e76c, 0xbd9b944e, 0x3db481e7, 0xbecc143a, 0x3e9ebdc5, 
    0x3e3272ad, 0x3dc00e45, 0x3e64facb, 0xbcdba227, 0xbb35e875, 0x3d9602ad, 0x3e43951d, 0xbe07a606, 
    0x3d26d87d, 0x3ef3fbb8, 0xbcaf6c96, 0x3e030efb, 0x3dad6ae7, 0xbcad3a7c, 0xbdd761b6, 0xbdc7443a, 
    0x3dc82de4, 0x3d6929f7, 0x3cef1429, 0x3e531a85, 0x3e073eac, 0xbe743ca1, 0x3f2f0890, 0x3e0c0450, 
    0x3eabd75e, 0xbb272f73, 0xbdf57c2e, 0x3dfe1f2e, 0xbd75ef8e, 0x3e915073, 0xbe15bd9f, 0x3e10758b, 
    0x3d818c55, 0x3d6d1127, 0xbd79eb1e, 0x3dc15406, 0xbe58d0b8, 0xbdc74622, 0x3d683033, 0xbe13ea1c, 
    0xbdb5c545, 0x3e80961b, 0xbc007faf, 0x3e626259, 0xbd981797, 0x3e4e7945, 0x3e942aed, 0x3c3579eb, 
    0x3e78811d, 0x3e5f7cac, 0x3dd7f527, 0x3e525bd4, 0x3e08d049, 0xbe2225a3, 0x3f4ba44a, 0x3d88d67c, 
    0x3d49ba28, 0xbc8384dd, 0x3d536346, 0x3ef2e1c4, 0x3d693a8e, 0x3eec4ad0, 0xbe2d46aa, 0x3dd26d57, 
    0xbb9ba115, 0x3dc3f5e8, 0xbdabbb5a, 0xbd6d3dbb, 0xbdade3a0, 0xbdf8abe3, 0xbdd27d3a, 0xbe39b172, 
    0x3e0ba110, 0x3e58c4ed, 0x3df08da8, 0x3e9ae197, 0x3ea44da3, 0xbdbc9435, 0x3df92ff2, 0xbdc713b6, 
    0xbda58074, 0xbe0b4c52, 0x3df14e37, 0x3d0d4164, 0xbba245ac, 0x3d177ad9, 0x3c815a16, 0x3e1c7c20, 
    0xbe1ac3e0, 0x3e1f357d, 0x3fc76387, 0xbd599aec, 0x3df2875c, 0xbdb6e7aa, 0xbe059235, 0xbd917b4c, 
    0x3ebdbb73, 0xbcc39685, 0xbd28962d, 0x3c7522d8, 0xbe28c7de, 0x3fefb468, 0xbe843bbf, 0xbc6cd6e7, 
    0xbd88524f, 0xbddee5f0, 0x3f6a8480, 0xbd5a3eb7, 0x3dc65040, 0xbcabefc1, 0xbd29e6b6, 0x3de0e5cc, 
    0xbde57742, 0xbe64ca1c, 0x3f6031ad, 0x3cca11a7, 0xbde6698c, 0x3bde5287, 0x3c8f29aa, 0x3ea7c56c, 
    0xbe081270, 0x3e5dc744, 0x3fe1efbb, 0xbb5bdd9d, 0x3d883500, 0xbd2d0373, 0xbcd7ce3f, 0x3d1ffcce, 
    0x3ed01f14, 0xbe218d24, 0xbc70472a, 0xbe11680c, 0xbe4a1145, 0x3fb2a5ed, 0xbe5bcbc3, 0xbd9eecf5, 
    0x3902077f, 0xbd8a3ae0, 0x3f66d98e, 0xbde632c7, 0x3d129499, 0x3d29c78f, 0xbde98bc5, 0x3e2c96ef, 
    0xbd0b7fb0, 0xbe76cb5c, 0x3f2373b1, 0xbb8bc5ca, 0xbd2fadea, 0x3db04cf2, 0x3dc9df4d, 0x3ee2a30d, 
    0xbdd21b12, 0x3e1606b4, 0x3fc773a8, 0xbc222e4e, 0x3c1bb52f, 0xbddb2fef, 0x3cd1e99d, 0x3cbdfd34, 
    0x3f00af7c, 0xbe4b9343, 0x3dd824bb, 0xbe628906, 0xbda4c28b, 0x3fcb63ea, 0x3dda1f12, 0xbcab3d31, 
    0x3e7ba7b3, 0xbe041a10, 0x3f8e445f, 0xbd80b7af, 0x3e277321, 0xbc9078f0, 0xbe0f5ab2, 0x3cf4a1e5, 
    0xbe811313, 0xbe84d1f3, 0x3e81c8ea, 0xbd2f0180, 0xbe4e8502, 0x3d4fa741, 0xbd97bdc3, 0xbdd65b56, 
    0x3dfd2ee3, 0x3e5ad1eb, 0x3ea5880d, 0x3d69a805, 0x3e6eaf72, 0x3e6b978b, 0x3df113a8, 0x3e3e29c1, 
    0xbdab38e7, 0x3a74cd3d, 0xbd7534da, 0xbd5ddc97, 0x3e8b14b3, 0x3e76d346, 0xbe978b1f, 0x3dd79acc, 
    0xbc71b555, 0xbef9ec74, 0x3e580c23, 0x3d9fa437, 0x3ead0ce7, 0xbd5aa3e2, 0xbc98b703, 0x3cb885be, 
    0x3e4be4d4, 0x3d92cc42, 0x3e9a2f72, 0xbd153cd6, 0x3e8a478f, 0xbe8f5f65, 0xbdef3277, 0xbe2196bc, 
    0xbd122f5f, 0x3e8ca50d, 0x3e764352, 0xbe3d3492, 0x3eab79b6, 0xbc1d9f91, 0xbd6f5da5, 0xbd2446d6, 
    0x3e993dec, 0xbb05a241, 0xbe000448, 0xbe502dd7, 0x3eed984b, 0x3e5b7d07, 0x3eecba51, 0xbe6d58e7, 
    0x3cd196ec, 0x3e1f85e9, 0x3e3f6f3b, 0xbb8020a3, 0x3e16411d, 0xbe3c618b, 0xbeb3f3d3, 0xbdd08f40, 
    0xbb477e90, 0xbc23d686, 0xbcdaa5c8, 0x3e01825c, 0x3ea206e8, 0xbe276b0d, 0xbe246136, 0xbd3cebca, 
    0xbe45d07f, 0x3f1c7b1a, 0x3ee600c5, 0xbec4b711, 0x3e94d604, 0xbdc31d4f, 0xbbefc609, 0xbe0eb29c, 
    0x3dd497f7, 0xbdb30db2, 0xbe2ea08f, 0x3c3b140f, 0xbe4f4574, 0x3e96e257, 0x3e825253, 0xbe1c209d, 
    0xbd2c0318, 0x3e3eecaa, 0x3eaa28e7, 0x3d646a52, 0x3e25b645, 0xbd95eaed, 0xbd5b040d, 0xbdb05546, 
    0xbe57ce09, 0xbe1491fc, 0x3d89316e, 0x3f1c3724, 0xbe03f379, 0x3f7bfb5f, 0x3cdc0ff0, 0x3e19b420, 
    0xbe692184, 0x3c697b4d, 0x3e575ee6, 0x3ee50b08, 0x3de8b88d, 0x3d6f4b3c, 0xbf76db5d, 0x3ed99900, 
    0x3d81db8b, 0xbe8e6a50, 0xbd18029d, 0xbea23311, 0xbe3808aa, 0x3e2d2289, 0x3d9a0229, 0xbe6603c1, 
    0x3e25e16e, 0xbc14246e, 0x3e357408, 0x3de57012, 0x3d2bab2b, 0xbd8ed86b, 0x3b302b7e, 0xbc4e8b18, 
    0x3dc18dc4, 0xbf5ffbf4, 0x3da0f849, 0x3f0ea5f3, 0x3c960af7, 0x3f03f4af, 0x3f42ddc8, 0x3e8a4015, 
    0xbe253f0f, 0x3e60d243, 0x3eaf3f6f, 0xbe3674a6, 0xbe71d792, 0x3d8a8a99, 0xbea09c79, 0x3e70d3f1, 
    0x3d74aaa6, 0xbe3a0b03, 0xbde5e642, 0xbe2706b3, 0xbe9869de, 0x3e0b7906, 0xbd88e33b, 0xbd385b84, 
    0xbe12a99b, 0x3d892936, 0x3d661b9b, 0x3e2652f4, 0x3dd31783, 0xbbb3bd5b, 0xbe2e0c63, 0xbe595760, 
    0x3d565b40, 0xbe62f518, 0x3e565965, 0x3f7dd197, 0xbe82266e, 0x3f979017, 0x3db95c11, 0x3d8fcb55, 
    0xbe13e696, 0xbda45166, 0x3ec5f93e, 0x3f4459db, 0xbd9851cc, 0x3e7831a4, 0xbe8bc22e, 0xbe04d1c1, 
    0x3e7e0dbc, 0xbe7e9743, 0xbc3368bb, 0xbee8e1ff, 0xbd4c7724, 0x3e85a07c, 0x3ec956c1, 0xbe4a67c6, 
    0xbd178115, 0x3e20eaa9, 0x3e9fd7c7, 0x3ee3679a, 0x3eb6c4f3, 0xbed43032, 0xbdb4d3c0, 0xbe245b4b, 
    0xbea38ef4, 0x3d34c9f5, 0x3e5e6134, 0xbdb83749, 0x3e089591, 0x3ddb4753, 0xbda20b42, 0xbdc32802, 
    0x3e8ae549, 0xbaf5fd1b, 0xbdddd1b0, 0xbe8477f3, 0x3dc99f14, 0x3e266bb0, 0xbf5ea7e8, 0xbd282dd0, 
    0xbf2e2eed, 0x3ec722d7, 0x3f58d6fc, 0xbdcc485a, 0xbed7207a, 0x3da80b17, 0x3bd2c420, 0xbe7b1f2d, 
    0x3e2dac81, 0x3e6d8025, 0xbef3c670, 0xbec15b1b, 0xbdd12144, 0xbe22c150, 0x3ee85796, 0xbc457e86, 
    0x3d3cc7b6, 0x3cd5e300, 0x3d9948c7, 0x3e1111d7, 0xbe556959, 0x3e50fd9b, 0x3cf11202, 0xbd56a6b5, 
    0x3e8a58f9, 0xbeb8a9a3, 0xbe0cc39c, 0xbec44ed9, 0x3e7a67e6, 0x3eb1f5d7, 0xbf0b2639, 0xbe98214f, 
    0xbefb3128, 0x3e81e320, 0x3f1e2ede, 0x3bcba9f6, 0xbe6ad97c, 0x3d87d1c4, 0x3e8446b5, 0xbdf48aa3, 
    0xbc25cd09, 0xbcefb0a9, 0xbeef2ad6, 0xbe580515, 0xbec813b6, 0xbe2270ed, 0x3f15e732, 0xbd87da0d, 
    0x3dfb5392, 0xbedd7ad4, 0xbe167b0f, 0x3e8d7e4a, 0xbf08d464, 0x3f34a4c2, 0xbe3a3166, 0xbe3db3eb, 
    0x3d1e8771, 0xbf22d95b, 0xbe6a9ea6, 0xbece6989, 0x3d94602c, 0x3f2acc41, 0xbefff233, 0xbea814fd, 
    0xbee9fcca, 0x3ce9ac60, 0x3ee3552f, 0xbd4a98a6, 0xbe0b1d2a, 0x3e35f8cc, 0xbe38732c, 0xbe98fc03, 
    0xbbf4b6ee, 0x3dbdd705, 0xbf1c2b93, 0x3e150c4d, 0xbf025aa9, 0xbebee8c1, 0x3f18f1b4, 0xbdda3b1d, 
    0xbe216192, 0x3d855efa, 0xbed12909, 0x3e8c5d2a, 0x3e1a9641, 0xbe9df7e4, 0x3efdf0ac, 0x3e526cda, 
    0x3e54fbe2, 0x3ccb4790, 0x3e2f2797, 0xbdfc4a9b, 0x3c433367, 0x3e165fc6, 0xbef3c591, 0x3eb57864, 
    0x3dcad69d, 0x3b7a116e, 0x3dad4288, 0xbe029dc0, 0xbe2240f4, 0x3e8c93dc, 0x3e0c4554, 0xbe3272d4, 
    0xbd886dea, 0x3edd8a5d, 0xbe01568f, 0xbd0374c7, 0x3e0133f2, 0x3d1eb36c, 0xbd295558, 0x3d1766e7, 
    0x3e35e14b, 0x3de8147c, 0x3c03f6dc, 0x3e0728b8, 0x3e1f2062, 0xbd8899c1, 0x3efc3cc0, 0x3e54114c, 
    0x3c8dc242, 0x3d1a1bec, 0xbd841cd7, 0x3eb242b6, 0xbc6e4894, 0x3e5f63bb, 0xbe3d1d92, 0x3dcf4c11, 
    0x3d024334, 0x3d76055b, 0x3c731180, 0x3d96c20e, 0xbe228935, 0xbd8f6a60, 0x3cf9a418, 0xbdb2533a, 
    0xbdaea7b5, 0x3ddf2c5f, 0x3dd295c8, 0x3e47e764, 0x3e354677, 0x3dbb427c, 0x3dbcfdf9, 0x3d7e0139, 
    0x3e3886e5, 0x3e559502, 0x3e58a55b, 0x3e86c9ce, 0x3dc5622c, 0xbf080ca9, 0x3e8e0279, 0x3e060c6f, 
    0xbe1086cc, 0xbd25c99a, 0x3dc4fcdd, 0x3f403503, 0x3d519164, 0x3ebc49bc, 0xbe417425, 0x3b40db63, 
    0xbdee98df, 0x3e1e05fb, 0x3c822d4f, 0xbdcc93cf, 0x3d0aecd0, 0xbe2d30d9, 0xbe818792, 0x3d30b1d9, 
    0xbc21854d, 0x3a419c61, 0x3e316ba1, 0x3e2eba71, 0x3eb84d53, 0xbd6df789, 0xbd98c394, 0xbd98eafe, 
    0x3d7c6e70, 0xbf361ba7, 0x3e557843, 0x3e83314d, 0x3f4e9a94, 0xbd17af20, 0xbe8be0d6, 0x3d6de43b, 
    0x3e80f17b, 0x3f9d6030, 0x3f0f61e8, 0xbe666b92, 0xbeb1bf95, 0xbe6b63a5, 0xbdd3a73e, 0xbe8250b5, 
    0x3eaf9335, 0xbf14f610, 0x3a944279, 0xbd2b35f2, 0xbdd07453, 0x3f558ef7, 0x3c9e28d6, 0x3e83368d, 
    0xbdfc43e7, 0xbd77836c, 0x3ee21a4d, 0xbde8fce7, 0x3d0bcf9e, 0xbc77aa3f, 0xbd18f5b1, 0xbd81f890, 
    0x3d98ea93, 0xbf204ef3, 0x3ec4dbf3, 0xbe210e24, 0x3d27eb58, 0x3e813cce, 0x3d34dd85, 0xbe8f2418, 
    0x3f721bc1, 0x3f4ecff4, 0x3eea6c6f, 0xbe5cff23, 0xbd4a545b, 0xbe2820cd, 0xbeb9a2f6, 0x3e49b68f, 
    0x3f070118, 0x3dd07baf, 0xbe4beaac, 0xbe1c649e, 0xbc7907ea, 0x3eee06af, 0x3d7d4f2b, 0x3e975fbc, 
    0xbdc024bb, 0x3e06dd18, 0x3effc6b9, 0xbea9944d, 0x3d78fe89, 0xbda59fdc, 0xbe1c8227, 0xbce70c3a, 
    0x3daf27c1, 0xbe9014f1, 0x3f067b88, 0xbe07bcb9, 0xbccd2412, 0xbdc29694, 0x3d60267e, 0xbdf16dc0, 
    0x3f49cf67, 0x3edd59db, 0x3f207e18, 0xbddc75cf, 0x3d8981d2, 0xbddc496d, 0xbe250c6a, 0x3d98f8a1, 
    0x3f1636ec, 0x3cc92467, 0xbdc67e3b, 0xbe644fa6, 0x3f39b0e9, 0x3ef2978c, 0x3f60ef7d, 0x3ea9d8d9, 
    0x3e0a29c8, 0x3d91bca1, 0x3f09739b, 0xbe344052, 0x3e69ebd1, 0xbdc8a962, 0xbe351f09, 0xbd714265, 
    0x3d490c0b, 0xbeae41e8, 0xbdcca494, 0x3e1cfb5c, 0x3ec72b3a, 0xbf027861, 0x3ea5efdb, 0x3cd66b24, 
    0x3db57524, 0xbd39d151, 0xbeb12f0a, 0x3d2efde2, 0x3e039bff, 0x3ec226fb, 0xbec2acbb, 0x3e21c53e, 
    0x3f547dd5, 0x3e11b7de, 0x3d163616, 0xbead4984, 0xbe92c0c7, 0xbea14b93, 0x3dd14772, 0x3d5f7b5a, 
    0xbc9ef318, 0x3ed8f1a2, 0xbe82a7a4, 0xbd73603c, 0xbed945f8, 0xbd48463c, 0xbe16998a, 0xbddf3a3c, 
    0xbbb3da84, 0xbe26f565, 0xbe946159, 0x3db8a5ea, 0x3e5581dd, 0xbeb991e6, 0xbe7fb6a8, 0x3e0fa644, 
    0xbd118a4b, 0xbcbcbf51, 0xbe830fcb, 0x3d5121af, 0xbe26434b, 0xbdd57772, 0xbd20666f, 0x3ef90de9, 
    0x3e87dbab, 0xbd57a3dc, 0x3e7ba29e, 0xbecb081f, 0x3ee0f6e1, 0x3c4fea2b, 0x3b80672e, 0xbe4b7952, 
    0xbbb50582, 0xbe9da7f0, 0xbe296830, 0x3de82550, 0xbda00ea7, 0xbe62021d, 0x3dca371a, 0x3d5d9d93, 
    0xbd69c9c0, 0xbe59412b, 0x3dc959b2, 0x3debd5c8, 0x3e350fc7, 0xbee2e97d, 0x3e983e0f, 0x3e833651, 
    0x3dd206dc, 0xbe0f75e4, 0xbeda9d73, 0x3ebe666b, 0x3df9e275, 0x3ef811ca, 0xbebebff7, 0x3ebbeabd, 
    0x3eacd575, 0x3e6f7f38, 0x3d117365, 0xbdb2ddc6, 0xbec0de90, 0xbec29598, 0xbe078cc8, 0xbd87c100, 
    0x3d8c23fd, 0x3cb81aca, 0xbea64220, 0xbe1b4754, 0xbedfbea7, 0xbdb16f48, 0xbeb32080, 0xbe290c51, 
    0xbec840e7, 0x3f0f3ef8, 0xbe636931, 0xbeba9317, 0x3d96c0b1, 0xbe572580, 0xbdd9c649, 0xbdfb996b, 
    0x3e840c18, 0x3e8c72fb, 0x3e18cf91, 0xbf0b9cc6, 0x3ea58184, 0x3e3c1a30, 0xbf8a2f70, 0x3e99cb59, 
    0xbeeb2138, 0x3d57967f, 0x3f06d727, 0xbdc199cd, 0xbf015f6c, 0x3e83448c, 0x3ef9a74a, 0xbef2213d, 
    0xbe79be9d, 0xbd20cc83, 0x3e67b443, 0xbd22c63e, 0x3f5963e7, 0xbe887043, 0xbdd55791, 0x3c6f7d86, 
    0xbde55791, 0x3e9328c3, 0xbec6202b, 0x3e2a40bf, 0xbca37ac3, 0x3e0dae59, 0xbdfeb112, 0xbe60f83f, 
    0x3ea4d131, 0x3e3130aa, 0x3e018872, 0xbf27f27e, 0x3f20379d, 0x3e09f672, 0xbf32a03e, 0xbeb10bd8, 
    0xbf11ef50, 0x3e090ec8, 0x3f279430, 0xbee75b08, 0xbe803127, 0x3e9887b8, 0x3e4485d1, 0xbeb2f873, 
    0xbd01aa61, 0xbddc65d0, 0x3cb359bf, 0xbd88076c, 0x3e48817a, 0xbe38cd11, 0x3f9e1965, 0x3e3b1c3a, 
    0x3c3e4a4b, 0x3ea87002, 0xbed4f32f, 0x3f2f81a6, 0xbf1e86fe, 0x3f96cedd, 0xbd8e3c9d, 0xbe653149, 
    0x3d9d8265, 0xbe7e4c86, 0xbcc18d18, 0xbec0118a, 0x3f0d7370, 0x3e9d8f6e, 0xbf1fa68e, 0xbe548e86, 
    0xbea8abc6, 0x3cb7ab98, 0x3e9089ca, 0xbf34c6fb, 0xbe6c47d5, 0x3e7d2b35, 0xbe027841, 0xbedefe30, 
    0xbe0457ce, 0xbf04b93e, 0x3d729962, 0x3e5502e3, 0xbe270a5a, 0xbeb34563, 0x3fba31d1, 0xbd97ef70, 
    0x3db7ce45, 0xbea6912b, 0xbe0896da, 0xbda76319, 0xbe13d069, 0x3ffa11bf, 0x3db8de34, 0xbe00ae4d, 
    0xbe16e6f1, 0xbe8800e4, 0x3e03e016, 0x3e8bc90c, 0xbe5abbad, 0xbe28269f, 0xbd7b1e12, 0x3cc6be97, 
    0xbeeb124a, 0x3dd7bc36, 0xbe3e7824, 0x3da2d89a, 0xbe20de99, 0x3f3c3302, 0xbe1d00c1, 0xbd32aee3, 
    0x3e0eea54, 0x3e506fd0, 0xbefb9c0e, 0xbdb8c013, 0xbed30c8e, 0x3dce89f8, 0xbdda4eb7, 0x3e007377, 
    0x3d1ebb43, 0xbf0e5e4a, 0xbe03902c, 0xbd9c2281, 0xbe314577, 0x40031b2b, 0x3e4eb7a9, 0x3e586f96, 
    0x3c2473fc, 0xbe06aefd, 0x3eb754e4, 0x3e12d377, 0xbea17811, 0xbe26332e, 0xbdcfdc20, 0xbb67496e, 
    0xbdc62d84, 0x3b1654e0, 0xbe3edbb8, 0x3e3c1e9a, 0x3d50fa6a, 0x3f8abbb4, 0x3d82817b, 0xbe023421, 
    0x3e1f982d, 0x3ee348ba, 0xbebfa0db, 0xbd5da8eb, 0xbed0c8a6, 0x3e10490a, 0xbcbdc762, 0x3c57ced5, 
    0xbcddac8c, 0xbf129e3d, 0x3bcc973d, 0x3c86d52e, 0xbe8be792, 0x4010d480, 0xbd90f6fc, 0x3d9eea90, 
    0xbd2d3c7c, 0xbe70975c, 0x3e789fdb, 0x3e5c9772, 0xbe61f8b3, 0x3d31f0c2, 0x3daf3510, 0xbe137ec5, 
    0x3c497d90, 0x3cd196ba, 0xbe29ef99, 0xbe2c41f5, 0x3d2037d7, 0x3f84e702, 0x3d30adc7, 0x3e055c24, 
    0xbe01bfe6, 0x3e4831dc, 0xbe104743, 0xbddae65c, 0xbead9888, 0x3d1d91a3, 0x3df2374a, 0xbe27285f, 
    0x3ba1370a, 0x3ec97967, 0x3ec0239f, 0x3df1eff8, 0xbe65027a, 0xbe397110, 0x3eb9dca9, 0x3dcf671f, 
    0xbe40f4ae, 0xbda42abf, 0x3c894545, 0x3ef6edf2, 0xbdaaf6d9, 0x3e07a5a3, 0x3e441708, 0x3f62a7d8, 
    0x3e2a3e97, 0x3e2169be, 0x3ec20d5f, 0xbe656536, 0xbd04bdd9, 0xbceb0f79, 0x3dd8f921, 0xbe6b4f8b, 
    0x3cdc8786, 0xbecad6d6, 0x3e09f85a, 0x3e013a1f, 0x3e0bf411, 0xbef4c489, 0x3bdc3c1b, 0xbdcf39f9, 
    0x3d970cf8, 0x3c853274, 0xbe85474a, 0x3e952a80, 0x3e1e7784, 0xbeea887e, 0x3cb100a4, 0x3dd4d5b3, 
    0xbd803727, 0x3cbeb2dd, 0xbe1e8992, 0xbe1eb71a, 0x3de84b1a, 0x3e3d34ed, 0xbe380deb, 0x3f4ef8c2, 
    0x3d9f605a, 0xbce71397, 0x3e53f840, 0xbdfce7f9, 0x3e90c465, 0xbe27b111, 0xbd593dc1, 0xbee08306, 
    0x3cdb61f9, 0x3d6cc0a6, 0xbdf491aa, 0x3d223330, 0x3d0d4b97, 0xbea16111, 0xbea347c2, 0x3d109bb9, 
    0xbe9b2a8a, 0x3bd9304a, 0xbe8c1cfc, 0x3efd1855, 0x3e2ae370, 0xbe77f7f5, 0xbd582ff6, 0x3d2f04b0, 
    0x3d84b7ae, 0x3da408b3, 0xbd67e709, 0x3d197aee, 0x3e9046ed, 0xbd254aef, 0xbe63bfc6, 0x3f1a3f51, 
    0xbe575974, 0x3e1d73b9, 0x3e429671, 0x3e45b435, 0x3e7a66e3, 0xbe9addf4, 0x3d8e97d3, 0xbe2f1f7b, 
    0xbd9367b1, 0xbdabb8c7, 0xbb8e7964, 0x3f06fe46, 0x3e2db00d, 0xbdc38370, 0x3e7cd16e, 0x3deb1c39, 
    0xbec09a24, 0x3eaeabf8, 0xbe369a31, 0x3e4df29f, 0xbce1446d, 0x3e136416, 0x3e8c75be, 0xbea137cd, 
    0xbd346589, 0x3d129bb5, 0xbd4cc605, 0x3e19ce18, 0x3e67119d, 0xbe5cd06b, 0xbc873101, 0x3fa5ddde, 
    0x3e2c54c1, 0x3e8b76dc, 0x3e90caa9, 0xbe8950b0, 0xbdf597b5, 0xbe9209cb, 0x3d22a89b, 0x3e45e943, 
    0xbe09f944, 0xbd3e3582, 0x3d9cf879, 0x3f01d51f, 0x3d8cf5b1, 0x3d669ace, 0x3ee9a879, 0xbdb57780, 
    0xbcf8507a, 0x3f4ddc4a, 0x3da60ace, 0xbe26d856, 0xbe36ff28, 0xbda43341, 0xbdbfa4d9, 0x3bd67606, 
    0xbaa54ada, 0x3d34ba98, 0xbd5b99e8, 0x3d51abb7, 0xbe639e82, 0xbd88717e, 0xbd6100e1, 0x3f87b28a, 
    0x3d6ab234, 0xbd84ea38, 0x3d5ad218, 0xbdfb1dbe, 0xbcc52d25, 0x3d06fe00, 0xbdef9909, 0xbe26f83a, 
    0x3da5c7c6, 0xbe14139f, 0x3ca7036b, 0xbe43ebd6, 0x3e0f000a, 0x3dd3e354, 0x3e223a6a, 0xbd956f58, 
    0x3e57eedc, 0x3f841aed, 0xbdcc2876, 0x3e25878c, 0xbe817482, 0xbf054afa, 0x3e813e04, 0xbe1b9589, 
    0x3d651ad6, 0x3e49e0c0, 0xbdb10158, 0x3e6b9c68, 0x3e9e5251, 0xbdefa778, 0x3d171c9b, 0x3f8f70b1, 
    0xbe23b895, 0x3ed5296b, 0x3ea8ccac, 0xbf05d8c4, 0xbce3e987, 0xbeba3a2a, 0x3b5f6be6, 0xbe1736fe, 
    0xbe18ac5f, 0xbdfe8e5c, 0x3e2a219c, 0x3e85c76e, 0xbe0cd273, 0xbe2bd7d2, 0x3e323435, 0xbc67de45, 
    0xbd7b9d86, 0xbe4799b0, 0x3d6c7c74, 0xbe69d23e, 0x3e25dd33, 0xbdfb707d, 0xbd6d63b4, 0xbd10eb0d, 
    0x3e05a911, 0x3e3bc2a7, 0xbc85e4e2, 0x3dee6f3d, 0x3e1bc10a, 0x3ea992f8, 0x3e06a72c, 0x3efa9b9b, 
    0x3dd7b322, 0x3f0757dc, 0x3e484ba4, 0xbe54a0db, 0x3f6afbf9, 0xbd1be44e, 0x3e9b9869, 0x3e0164b7, 
    0x3d2aa49e, 0xbea0ede5, 0x3d17e85e, 0xbde8e1e7, 0x3e81cf37, 0xbe67ccfc, 0x3cb887b0, 0x3d899d99, 
    0x3e2b5b95, 0x3dc84f70, 0x3e17217b, 0x3c71ede5, 0xbde31b80, 0xbef4285c, 0xbde4fc9b, 0xbe188d05, 
    0xbefb0f46, 0x3ec0f0e3, 0x3c88ef7c, 0xbe5fc073, 0x3e54824b, 0x3dbe0951, 0xbd5aa680, 0x3cfe9419, 
    0x3edb29c4, 0xbef0796a, 0xbe9a1210, 0xbe88c951, 0x3efe694b, 0x3dbc52de, 0x3f5219aa, 0xbe8a777d, 
    0x3d2ec753, 0x3e6fd45a, 0x3e3542e5, 0xbe5d7559, 0xbd1cc581, 0xbe26dd85, 0x3d91bd31, 0x3debbbd8, 
    0xbe6db506, 0x3d60c842, 0xbe9a9ccd, 0x3e728022, 0x3ef0e5ee, 0xbe5378e4, 0xbded3bfc, 0xbd20ba3b, 
    0x3ec01125, 0x3e23ca4b, 0x3e8a5b34, 0xbe5ce787, 0x3e7834d4, 0xbd4b8f35, 0xbe2b2863, 0x3e84cc8c, 
    0x3e98c38a, 0x3d84c86a, 0xbe6e4106, 0x3bdb661b, 0xbddebeb4, 0xbd7e5755, 0x3e304df5, 0xbd7ff928, 
    0xbd01a6b3, 0x3ee16f16, 0xbdce140e, 0xbd308fb4, 0x3cb7b72c, 0xbde03f97, 0x3cdd55c5, 0x3cc4bbf5, 
    0x3e936659, 0x3e9509bd, 0x3e41026e, 0x3f282628, 0x3db6776b, 0xbc5b2fcb, 0x3f23d8b4, 0x3e15b502, 
    0x3e41bd4e, 0x3d49c14a, 0x3eafb8a0, 0x3f1d9059, 0x3e01fe7e, 0x3f086fb0, 0xbd010eb0, 0x3e662e2f, 
    0x3ebf2dd5, 0x3e597358, 0x3e86c284, 0xbdbad992, 0x3e3632d0, 0x3e1951cd, 0x3e9f29f7, 0xbe52116f, 
    0x3d74b293, 0xbecf602f, 0x3d9cec18, 0x3e506d6f, 0x3e31c477, 0xbe4ad13b, 0x3e2c5019, 0x3d1964aa, 
    0x3cf6635d, 0x3eb3a7d7, 0xbe564976, 0x3dd28fcd, 0x3e78f26e, 0xbe506fdb, 0x3e2f3d67, 0x3db57eed, 
    0x3e1609e6, 0x3cb7ccbe, 0x3de75788, 0x3e3e1c18, 0xbcbfbbb1, 0xbe6f3315, 0xbe4f58f9, 0x3dfbc680, 
    0x3cb4b510, 0x3e9fa437, 0x3f1ad051, 0xbe7d0710, 0xbd4a5c1c, 0xbe87d01e, 0xbcafb278, 0xbeadca72, 
    0x3cf68d4a, 0x3e3c0920, 0x3e22ac69, 0x3f037192, 0x3d933359, 0xbf084b61, 0xbd8f8cee, 0xbd74185a, 
    0xbdda1fd0, 0xbdc2b3d6, 0xbe7c5320, 0x3ef8989a, 0x3e8b7a26, 0xbe5d53af, 0x3eab9ca4, 0xbdd084de, 
    0x3e697567, 0x3eae2c8a, 0x3e61d0ff, 0xbe29f429, 0xbe21404a, 0xbdce8d12, 0xbe5b50bc, 0xbd4922d3, 
    0xbe8f4e9b, 0x3e6d7987, 0xbdea930b, 0x3e2d4b12, 0x3db1cb0e, 0xbdffb482, 0xbe033498, 0xbd49972b, 
    0xbd1d6453, 0x3e5db1cb, 0x3d12dde0, 0x3f0f1cfe, 0x3e46abf7, 0xbe301853, 0x3d3f8900, 0x3d919e3c, 
    0xfffffe2a, 0x00000004, 0x00000040, 0x3e87c0b4, 0xbe64ea0e, 0xbecbe421, 0x3df87f0e, 0xbddc56ff, 
    0xbe956add, 0x3ea332aa, 0x3d58f260, 0xbdf9fc92, 0xbda413b5, 0x3e9171ab, 0x3e597393, 0x3e99cb39, 
    0xbc528a2e, 0x3d3ab99a, 0x3e9205bf, 0xfffffe76, 0x00000004, 0x00000040, 0x3eecfcde, 0x3f9872ee, 
    0x3f0489a4, 0x3fc1e0e1, 0xbc5af690, 0x3e3b086d, 0x3f7a4643, 0x3e5e44b6, 0x3ec39230, 0xbf6c1dea, 
    0xc012cba7, 0xbdb34354, 0x3f7b678f, 0x3f18a1a9, 0x3f28e126, 0xbe82bf42, 0xfffffec2, 0x00000004, 
    0x00000080, 0xbef46175, 0xbe764dec, 0xbfaf6d57, 0x3f8e0bc5, 0xbf1c1fca, 0xbd303e0c, 0xbe675e9a, 
    0x3f3319f8, 0x3ff318b2, 0xbef725b0, 0xbfdab87a, 0x3ecc4081, 0xbf73055e, 0xbfbb1e42, 0xbee214a8, 
    0xc0130472, 0xbd8f2d33, 0x3fbd5e88, 0xbfe2218e, 0xbee3e866, 0x3ae14400, 0xbf120499, 0x3fb44f11, 
    0xbf9b3e51, 0xbf1f2f52, 0x3e16adc2, 0x3ffbb535, 0xbf36e819, 0xbef8f7ae, 0xbf1ae2a6, 0x3c0de260, 
    0xbfc420c4, 0xffffed90, 0xffffed94, 0x0000000f, 0x52494c4d, 0x6e6f4320, 0x74726576, 0x002e6465, 
    0x00000001, 0x00000014, 0x000e0000, 0x00140018, 0x000c0010, 0x00040008, 0x0000000e, 0x00000014, 
    0x0000001c, 0x0000038c, 0x00000390, 0x00000394, 0x00000004, 0x6e69616d, 0x00000000, 0x0000000f, 
    0x00000350, 0x000002f4, 0x000002a0, 0x0000025c, 0x00000238, 0x000001e4, 0x000001c0, 0x0000017c, 
    0x00000138, 0x00000114, 0x000000d0, 0x000000ac, 0x00000078, 0x00000040, 0x00000004, 0xfffffd52, 
    0x0000001c, 0x09000000, 0x0000001c, 0x00000020, 0x00000005, 0x00060000, 0x00040008, 0x00000006, 
    0x3f800000, 0x00000001, 0x00000021, 0x00000001, 0x00000020, 0xfffffd8a, 0x00000014, 0x08000000, 
    0x00000010, 0x00000014, 0x00000004, 0xffffee78, 0x00000001, 0x00000020, 0x00000003, 0x0000001f, 
    0x0000000f, 0x00000010, 0xfffffdbe, 0x00000014, 0x1b000000, 0x00000010, 0x00000014, 0x00000003, 
    0xffffeeac, 0x00000001, 0x0000001f, 0x00000002, 0x0000001e, 0x00000011, 0xfffffd92, 0x00000008, 
    0x0000000c, 0x00000001, 0x0000001e, 0x00000002, 0x0000001d, 0x00000007, 0xfffffe0e, 0x00000014, 
    0x05000000, 0x00000024, 0x00000028, 0x00000002, 0xfffffefe, 0x00000002, 0x00000001, 0x00000002, 
    0x00000001, 0x01000000, 0x00000001, 0x0000001d, 0x00000001, 0x0000001c, 0xfffffdf2, 0x00000008, 
    0x0000000c, 0x00000001, 0x0000001c, 0x00000002, 0x0000001b, 0x00000008, 0xfffffe6e, 0x00000014, 
    0x01000000, 0x0000001c, 0x00000020, 0x00000001, 0xfffffe60, 0x01000000, 0x00000001, 0x00000001, 
    0x00000001, 0x0000001b, 0x00000003, 0x0000001a, 0x00000004, 0x00000001, 0xfffffeae, 0x00000014, 
    0x01000000, 0x0000001c, 0x00000020, 0x00000001, 0xfffffea0, 0x01000000, 0x00000001, 0x00000001, 
    0x00000001, 0x0000001a, 0x00000003, 0x00000019, 0x0000000b, 0x0000000c, 0xfffffe92, 0x00000008, 
    0x0000000c, 0x00000001, 0x00000019, 0x00000002, 0x00000018, 0x00000009, 0xffffff0e, 0x00000024, 
    0x05000000, 0x00000034, 0x00000038, 0x00000002, 0x000e0000, 0x00170018, 0x000c0010, 0x00040008, 
    0x0000000e, 0x00000002, 0x00000001, 0x00000002, 0x00000001, 0x01000000, 0x00000001, 0x00000018, 
    0x00000001, 0x00000017, 0xffffff02, 0x00000008, 0x0000000c, 0x00000001, 0x00000017, 0x00000002, 
    0x00000016, 0x0000000a, 0xffffff7e, 0x00000014, 0x01000000, 0x0000001c, 0x00000020, 0x00000001, 
    0xffffff70, 0x01000000, 0x00000001, 0x00000001, 0x00000001, 0x00000016, 0x00000003, 0x00000015, 
    0x00000005, 0x00000002, 0xffffffbe, 0x00000014, 0x01000000, 0x0000001c, 0x00000020, 0x00000001, 
    0xffffffb0, 0x01000000, 0x00000001, 0x00000001, 0x00000001, 0x00000015, 0x00000003, 0x00000014, 
    0x0000000d, 0x0000000e, 0x000e0000, 0x00140018, 0x000c0010, 0x0004000b, 0x0000000e, 0x00000020, 
    0x01000000, 0x00000028, 0x0000002c, 0x00000001, 0x0010000c, 0x000c0000, 0x00070008, 0x0000000c, 
    0x01000000, 0x00000001, 0x00000002, 0x00000001, 0x00000014, 0x00000003, 0x00000013, 0x00000006, 
    0x00000003, 0x000a0000, 0x0000000c, 0x00040008, 0x0000000a, 0x00000008, 0x0000000c, 0x00000001, 
    0x00000013, 0x00000002, 0x00000000, 0x00000012, 0x00000001, 0x00000021, 0x00000001, 0x00000000, 
    0x00000022, 0x00000e78, 0x00000e24, 0x00000de8, 0x00000dac, 0x00000d64, 0x00000d1c, 0x00000cd4, 
    0x00000c94, 0x00000c3c, 0x00000bfc, 0x00000bbc, 0x00000b70, 0x00000b30, 0x00000ae4, 0x00000aa4, 
    0x00000a60, 0x00000a20, 0x000009e0, 0x00000974, 0x00000900, 0x000007c8, 0x00000700, 0x000005c8, 
    0x0000055c, 0x000004f4, 0x00000480, 0x000003b4, 0x00000278, 0x0000020c, 0x000001a4, 0x00000140, 
    0x000000e0, 0x00000050, 0x00000004, 0xfffff226, 0x01000000, 0x00000010, 0x00000010, 0x00000022, 
    0x00000028, 0xfffff210, 0x00000019, 0x74617453, 0x6c756665, 0x74726150, 0x6f697469, 0x4364656e, 
    0x3a6c6c61, 0x00000030, 0x00000002, 0x00000001, 0x00000004, 0xfffff26e, 0x01000000, 0x00000010, 
    0x00000010, 0x00000021, 0x0000006c, 0xfffff258, 0x0000005e, 0x65646f6d, 0x6f632f6c, 0x6431766e, 
    0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x2f37315f, 0x4d74614d, 
    0x6d3b6c75, 0x6c65646f, 0x6e6f632f, 0x2d643176, 0x6964656d, 0x622d6d75, 0x6e616c61, 0x2d646563, 
    0x616c2f31, 0x5f726579, 0x422f3731, 0x41736169, 0x00006464, 0x00000002, 0x00000001, 0x00000004, 
    0xfffff2fa, 0x01000000, 0x00000010, 0x00000010, 0x00000020, 0x0000003c, 0xfffff2e4, 0x0000002c, 
    0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 
    0x72657961, 0x2f36315f, 0x6e61654d, 0x00000000, 0x00000002, 0x00000001, 0x00000020, 0xfffff356, 
    0x01000000, 0x00000010, 0x00000010, 0x0000001f, 0x0000003c, 0xfffff340, 0x0000002f, 0x65646f6d, 
    0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 
    0x2f35315f, 0x65757153, 0x00657a65, 0x00000003, 0x00000001, 0x000007d0, 0x00000020, 0xfffff3b6, 
    0x01000000, 0x00000010, 0x00000010, 0x0000001e, 0x0000003c, 0xfffff3a0, 0x0000002f, 0x65646f6d, 
    0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 
    0x2f35315f, 0x5078614d, 0x006c6f6f, 0x00000004, 0x00000001, 0x000007d0, 0x00000001, 0x00000020, 
    0xfffff41a, 0x01000000, 0x00000010, 0x00000010, 0x0000001d, 0x00000040, 0xfffff404, 0x00000032, 
    0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 
    0x72657961, 0x2f35315f, 0x61707845, 0x6944646e, 0x0000736d, 0x00000004, 0x00000001, 0x00000fa0, 
    0x00000001, 0x00000020, 0xfffff482, 0x01000000, 0x00000010, 0x00000010, 0x0000001c, 0x00000110, 
    0xfffff46c, 0x00000103, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 
    0x6465636e, 0x6c2f312d, 0x72657961, 0x2f34315f, 0x756c6552, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 
    0x656d2d64, 0x6d756964, 0x6c61622d, 0x65636e61, 0x2f312d64, 0x6579616c, 0x33315f72, 0x7461622f, 
    0x6f6e6863, 0x612f6d72, 0x315f6464, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x656d2d64, 0x6d756964, 
    0x6c61622d, 0x65636e61, 0x2f312d64, 0x6579616c, 0x32315f72, 0x6e6f432f, 0x2f443176, 0x65757153, 
    0x3b657a65, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 
    0x6c2f312d, 0x72657961, 0x2f33315f, 0x63746162, 0x726f6e68, 0x756d2f6d, 0x3b315f6c, 0x646f6d3b, 
    0x632f6c65, 0x31766e6f, 0x656d2d64, 0x6d756964, 0x6c61622d, 0x65636e61, 0x2f312d64, 0x6579616c, 
    0x32315f72, 0x6e6f432f, 0x00443176, 0x00000004, 0x00000001, 0x00000001, 0x00000fa0, 0x00000020, 
    0xfffff5ba, 0x01000000, 0x00000010, 0x00000010, 0x0000001b, 0x000000a0, 0xfffff5a4, 0x00000092, 
    0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 
    0x72657961, 0x2f31315f, 0x756c6552, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x656d2d64, 0x6d756964, 
    0x6c61622d, 0x65636e61, 0x2f312d64, 0x6579616c, 0x30315f72, 0x6e6f432f, 0x2f443176, 0x65757153, 
    0x3b657a65, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 
    0x6c2f312d, 0x72657961, 0x2f30315f, 0x766e6f43, 0x00004431, 0x00000004, 0x00000001, 0x00000001, 
    0x00000fa0, 0x00000020, 0xfffff682, 0x01000000, 0x00000010, 0x00000010, 0x0000001a, 0x00000048, 
    0xfffff66c, 0x00000039, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 
    0x6465636e, 0x6c2f312d, 0x72657961, 0x2f30315f, 0x766e6f43, 0x452f4431, 0x6e617078, 0x6d694464, 
    0x00000073, 0x00000004, 0x00000001, 0x00000001, 0x00000fa0, 0x00000010, 0xfffff6f2, 0x01000000, 
    0x00000010, 0x00000010, 0x00000019, 0x0000003c, 0xfffff6dc, 0x0000002e, 0x65646f6d, 0x6f632f6c, 
    0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x4d2f395f, 
    0x6f507861, 0x00006c6f, 0x00000004, 0x00000001, 0x00000fa0, 0x00000001, 0x00000010, 0xfffff756, 
    0x01000000, 0x00000010, 0x00000010, 0x00000018, 0x00000040, 0xfffff740, 0x00000031, 0x65646f6d, 
    0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 
    0x452f395f, 0x6e617078, 0x6d694464, 0x00000073, 0x00000004, 0x00000001, 0x00001f40, 0x00000001, 
    0x00000010, 0xfffff7be, 0x01000000, 0x00000010, 0x00000010, 0x00000017, 0x0000010c, 0xfffff7a8, 
    0x000000fe, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 
    0x6c2f312d, 0x72657961, 0x522f385f, 0x3b756c65, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 
    0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x622f375f, 0x68637461, 0x6d726f6e, 
    0x6464612f, 0x6d3b315f, 0x6c65646f, 0x6e6f632f, 0x2d643176, 0x6964656d, 0x622d6d75, 0x6e616c61, 
    0x2d646563, 0x616c2f31, 0x5f726579, 0x6f432f36, 0x4431766e, 0x7571532f, 0x657a6565, 0x646f6d3b, 
    0x632f6c65, 0x31766e6f, 0x656d2d64, 0x6d756964, 0x6c61622d, 0x65636e61, 0x2f312d64, 0x6579616c, 
    0x2f375f72, 0x63746162, 0x726f6e68, 0x756d2f6d, 0x3b315f6c, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 
    0x656d2d64, 0x6d756964, 0x6c61622d, 0x65636e61, 0x2f312d64, 0x6579616c, 0x2f365f72, 0x766e6f43, 
    0x00004431, 0x00000004, 0x00000001, 0x00000001, 0x00001f40, 0x00000010, 0xfffff8f2, 0x01000000, 
    0x00000010, 0x00000010, 0x00000016, 0x0000009c, 0xfffff8dc, 0x0000008f, 0x65646f6d, 0x6f632f6c, 
    0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x522f355f, 
    0x3b756c65, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 
    0x6c2f312d, 0x72657961, 0x432f345f, 0x31766e6f, 0x71532f44, 0x7a656575, 0x6f6d3b65, 0x2f6c6564, 
    0x766e6f63, 0x6d2d6431, 0x75696465, 0x61622d6d, 0x636e616c, 0x312d6465, 0x79616c2f, 0x345f7265, 
    0x6e6f432f, 0x00443176, 0x00000004, 0x00000001, 0x00000001, 0x00001f40, 0x00000010, 0xfffff9b6, 
    0x01000000, 0x00000010, 0x00000010, 0x00000015, 0x0000010c, 0xfffff9a0, 0x000000fe, 0x65646f6d, 
    0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 
    0x522f335f, 0x3b756c65, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 
    0x6465636e, 0x6c2f312d, 0x72657961, 0x622f325f, 0x68637461, 0x6d726f6e, 0x6464612f, 0x6d3b315f, 
    0x6c65646f, 0x6e6f632f, 0x2d643176, 0x6964656d, 0x622d6d75, 0x6e616c61, 0x2d646563, 0x616c2f31, 
    0x5f726579, 0x6f432f31, 0x4431766e, 0x7571532f, 0x657a6565, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 
    0x656d2d64, 0x6d756964, 0x6c61622d, 0x65636e61, 0x2f312d64, 0x6579616c, 0x2f325f72, 0x63746162, 
    0x726f6e68, 0x756d2f6d, 0x3b315f6c, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x656d2d64, 0x6d756964, 
    0x6c61622d, 0x65636e61, 0x2f312d64, 0x6579616c, 0x2f315f72, 0x766e6f43, 0x00004431, 0x00000004, 
    0x00000001, 0x00000001, 0x00001f40, 0x00000010, 0xfffffaea, 0x01000000, 0x00000010, 0x00000010, 
    0x00000014, 0x00000048, 0xfffffad4, 0x00000039, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 
    0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x432f315f, 0x31766e6f, 0x78452f44, 
    0x646e6170, 0x736d6944, 0x00000031, 0x00000004, 0x00000001, 0x00000001, 0x00003e80, 0x00000002, 
    0xfffffd22, 0x01000000, 0x00000014, 0x00000014, 0x00000013, 0x02000000, 0x00000048, 0xfffffb48, 
    0x00000038, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 
    0x6c2f312d, 0x72657961, 0x432f315f, 0x31766e6f, 0x78452f44, 0x646e6170, 0x736d6944, 0x00000000, 
    0x00000001, 0x00000004, 0xfffffd8a, 0x01000000, 0x00000014, 0x00000014, 0x00000012, 0x02000000, 
    0x00000020, 0xfffffbb0, 0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3631746e, 0x00000000, 
    0x00000000, 0xfffffbfe, 0x01000000, 0x00000010, 0x00000010, 0x00000011, 0x00000020, 0xfffffbe8, 
    0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3531746e, 0x00000000, 0x00000001, 0x00000004, 
    0xfffffc3a, 0x01000000, 0x00000010, 0x00000010, 0x00000010, 0x00000020, 0xfffffc24, 0x00000010, 
    0x74697261, 0x6f632e68, 0x6174736e, 0x3431746e, 0x00000000, 0x00000002, 0x00000004, 0x00000020, 
    0xfffffc7a, 0x01000000, 0x00000010, 0x00000010, 0x0000000f, 0x00000020, 0xfffffc64, 0x00000010, 
    0x74697261, 0x6f632e68, 0x6174736e, 0x3331746e, 0x00000000, 0x00000001, 0x00000010, 0xfffffcb6, 
    0x01000000, 0x00000010, 0x00000010, 0x0000000e, 0x00000020, 0xfffffca0, 0x00000010, 0x74697261, 
    0x6f632e68, 0x6174736e, 0x3231746e, 0x00000000, 0x00000004, 0x00000010, 0x00000001, 0x00000003, 
    0x00000010, 0xfffffcfe, 0x01000000, 0x00000010, 0x00000010, 0x0000000d, 0x00000020, 0xfffffce8, 
    0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3131746e, 0x00000000, 0x00000001, 0x00000020, 
    0xfffffd3a, 0x01000000, 0x00000010, 0x00000010, 0x0000000c, 0x00000020, 0xfffffd24, 0x00000010, 
    0x74697261, 0x6f632e68, 0x6174736e, 0x3031746e, 0x00000000, 0x00000004, 0x00000020, 0x00000001, 
    0x00000003, 0x00000010, 0xffffff4a, 0x01000000, 0x00000014, 0x00000014, 0x0000000b, 0x02000000, 
    0x0000001c, 0xfffffd70, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0039746e, 0x00000001, 
    0x00000004, 0xffffff86, 0x01000000, 0x00000014, 0x00000014, 0x0000000a, 0x02000000, 0x0000001c, 
    0xfffffdac, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0038746e, 0x00000001, 0x00000004, 
    0xffffffc2, 0x01000000, 0x00000014, 0x00000014, 0x00000009, 0x02000000, 0x0000001c, 0xfffffde8, 
    0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0037746e, 0x00000001, 0x00000004, 0x00160000, 
    0x0018001c, 0x00100017, 0x0008000c, 0x00000000, 0x00070000, 0x00000016, 0x01000000, 0x00000014, 
    0x00000014, 0x00000008, 0x02000000, 0x0000001c, 0xfffffe3c, 0x0000000f, 0x74697261, 0x6f632e68, 
    0x6174736e, 0x0036746e, 0x00000001, 0x00000003, 0xfffffe8a, 0x01000000, 0x00000010, 0x00000010, 
    0x00000007, 0x0000001c, 0xfffffe74, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0035746e, 
    0x00000004, 0x00000010, 0x00000001, 0x00000003, 0x00000002, 0xfffffece, 0x01000000, 0x00000010, 
    0x00000010, 0x00000006, 0x0000001c, 0xfffffeb8, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 
    0x0034746e, 0x00000004, 0x00000010, 0x00000001, 0x00000003, 0x00000010, 0xffffff12, 0x01000000, 
    0x00000010, 0x00000010, 0x00000005, 0x0000001c, 0xfffffefc, 0x0000000f, 0x74697261, 0x6f632e68, 
    0x6174736e, 0x0033746e, 0x00000004, 0x00000020, 0x00000001, 0x00000003, 0x00000020, 0xffffff56, 
    0x01000000, 0x00000010, 0x00000010, 0x00000004, 0x0000001c, 0xffffff40, 0x0000000f, 0x74697261, 
    0x6f632e68, 0x6174736e, 0x0032746e, 0x00000001, 0x00000010, 0xffffff8e, 0x01000000, 0x00000010, 
    0x00000010, 0x00000003, 0x0000001c, 0xffffff78, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 
    0x0031746e, 0x00000001, 0x00000010, 0xffffffc6, 0x01000000, 0x00000010, 0x00000010, 0x00000002, 
    0x0000001c, 0xffffffb0, 0x0000000e, 0x74697261, 0x6f632e68, 0x6174736e, 0x0000746e, 0x00000001, 
    0x00000020, 0x00160000, 0x00140018, 0x00100000, 0x0008000c, 0x00000000, 0x00070000, 0x00000016, 
    0x01000000, 0x00000014, 0x00000014, 0x00000001, 0x0000002c, 0x00040004, 0x00000004, 0x00000019, 
    0x76726573, 0x5f676e69, 0x61666564, 0x5f746c75, 0x6579616c, 0x3a305f72, 0x00000030, 0x00000004, 
    0x00000001, 0x00001f40, 0x00000002, 0x00000002, 0x00000006, 0x00000060, 0x00000044, 0x00000034, 
    0x00000024, 0x00000014, 0x00000004, 0xffffffc4, 0x00000019, 0x19000000, 0xffffffd0, 0x00000009, 
    0x09000000, 0xffffffdc, 0x00000028, 0x28000000, 0xffffffe8, 0x00000011, 0x11000000, 0xfffffff4, 
    0x00000003, 0x03000000, 0x000c000c, 0x0000000b, 0x00040000, 0x0000000c, 0x00000016, 0x16000000
};

// Memory mapped buffers
#define _K5              ((uint8_t *)_k5)                    // u8[31744] (31744 bytes)
#define _K10             ((int32_t *)(_state + 0x0011eae0))  // s32[3] (12 bytes)
#define _K11             ((float *)(_state + 0x0011eaec))    // f32[3] (12 bytes)
#define _K2              ((int8_t *)(_state + 0x00000000))   // s8[64208] (64208 bytes)
#define _K4              ((uint8_t *)(_state + 0x0000fae0))  // u8[1110016] (1110016 bytes)
#define _K8              ((int8_t *)(_state + 0x0000fad0))   // s8[8] (8 bytes)
#define _K1              ((float *)(_buffer + 0x00000000))   // f32[8000,2] (64000 bytes)
#define _K12             ((float *)(_buffer + 0x0002ee00))   // f32[6] (24 bytes)
#define _K3              ((float *)(_buffer + 0x0000fa00))   // f32[8000,2,2] (128000 bytes)

#define IPWIN_RET_SUCCESS 0
#define IPWIN_RET_NODATA -1
#define IPWIN_RET_ERROR -2
#define IPWIN_RET_STREAMEND -3

#ifdef IMAI_PROFILING
	static uint32_t region_profile_visits[IMAI_REGIONS_COUNT];
	static uint64_t region_start[IMAI_REGIONS_COUNT];
	static uint64_t region_profile_sum[IMAI_REGIONS_COUNT];
	static uint64_t region_profile_max[IMAI_REGIONS_COUNT];
	static char* region_names[] = IMAI_REGIONS_NAMES;
	static const char* region_notes[] = IMAI_REGIONS_NOTES;

	#define __HOOK_REGION(entered, region_id) hook_region(entered, region_id)
	#define __CLOSE_HOOKS() close_regions()

	int IMAI_get_ticks(uint64_t *val) { return 0; }
    int (*IMAI_get_ticks_ptr)(uint64_t* val) = &IMAI_get_ticks;

	ATTRIB_WEAK void IMAI_hook_region(bool entered, int32_t region_id) {
		uint64_t ticks = 0;
		// assign the current tick count with a BSP or custom function
		IMAI_get_ticks_ptr(&ticks);
		 if (entered) {
			 region_start[region_id] = ticks;
		}
		else {
			ticks = ticks - region_start[region_id];
			region_profile_visits[region_id]++;
			if (ticks > region_profile_max[region_id])
				region_profile_max[region_id] = ticks;
			region_profile_sum[region_id] += ticks;
		}
	}
	
	static bool region_entered[IMAI_REGIONS_COUNT];
	
	static inline void hook_region(bool entered, int32_t region_id) {
		region_entered[region_id] = entered;
		IMAI_hook_region(entered, region_id);
	}
	
	static inline void close_regions() {
		uint32_t i = 0;
		for (i = 0; i < IMAI_REGIONS_COUNT; i++)
			if (region_entered[i])
				hook_region(false, i);
	}

	void IMAI_print_region_profiling(void) {
		uint32_t i = 0;
		printf("Region profiling results:\r\n");
		for (i = 0; i < IMAI_REGIONS_COUNT; i++) {
			if (region_notes[i] != NULL && region_notes[i][0] != '\0') {
				printf("Region \"%s\"; %s\r\n",
					region_names[i],
					region_notes[i]);
			}
			else {
				printf("Region \"%s\"; visits: %lu, max cycles: %-10.2f, avg cycles: %-10.2f\r\n",
					region_names[i],
					(unsigned long)region_profile_visits[i],
					(float)region_profile_max[i],
					(float)region_profile_sum[i] / region_profile_visits[i]);
			}
		}
		printf("\r\n");
	}
#else
	#define __HOOK_REGION(entered, region_id) do { } while(0)
	#define __CLOSE_HOOKS() do { } while(0)

	void IMAI_print_region_profiling(void) {
		(void)0;
	}
#endif

// Represents a Circular Buffer
// https://en.wikipedia.org/wiki/Circular_buffer
typedef struct
{
	char *buf;
	int size;		// total bytes allocated in *buf
	int used;		// current bytes used in buffer.
	int read;
	int write;
} cbuffer_t;

#define CBUFFER_SUCCESS 0
#define CBUFFER_NOMEM -1

// Reset instance (clear buffer)
static inline void cbuffer_reset(cbuffer_t* buf) {
	buf->read = 0;
	buf->write = 0;
	buf->used = 0;
}

// Initializes a cbuffer handle with given memory and size.
static inline void cbuffer_init(cbuffer_t *dest, void *mem, int size) {
	dest->buf = mem;
	dest->size = size;
	cbuffer_reset(dest);
}

// Returns the number of free bytes in buffer.
static inline int cbuffer_get_free(cbuffer_t *buf) {
	return buf->size - buf->used;
}

// Returns the number of used bytes in buffer.
static inline int cbuffer_get_used(cbuffer_t *buf) {
	return buf->used;
}

// Writes given data to buffer.
// Returns CBUFFER_SUCCESS or CBUFFER_NOMEM if out of memory.
static inline int cbuffer_enqueue(cbuffer_t *buf, const void *data, int data_size) {
	int free = cbuffer_get_free(buf);

	// Out of memory?
	if (free < data_size)
		return CBUFFER_NOMEM;

	// Is the data split in the end?
	if (buf->write + data_size > buf->size) {
		int first_size = buf->size - buf->write;
		memcpy(buf->buf + buf->write, data, first_size);
		memcpy(buf->buf, ((char *)data) + first_size, data_size - first_size);
	}
	else {
		memcpy(buf->buf + buf->write, data, data_size);
	}
	buf->write += data_size;
	if (buf->write >= buf->size)
		buf->write -= buf->size;

	buf->used += data_size;
	return CBUFFER_SUCCESS;
}

// Advances the read pointer by given count.
// Returns CBUFFER_SUCCESS on success or CBUFFER_NOMEM if count is more than available data
static inline int cbuffer_advance(cbuffer_t *buf, int count) {
	int used = cbuffer_get_used(buf);

	if (count > used)
		return CBUFFER_NOMEM;

	buf->read += count;
	if (buf->read >= buf->size)
		buf->read -= buf->size;

	// Reset pointers to 0 if buffer is empty in order to avoid unwanted wrapps.
	if (buf->read == buf->write) {
		buf->read = 0;
		buf->write = 0;
	}

	buf->used -= count;
	return CBUFFER_SUCCESS;
}

// Returns a read pointer at given offset and  
// updates *can_read_bytes (if not NULL) with the number of bytes that can be read.
// 
// Note! Byte count written to can_read_bytes can be less than what cbuffer_get_used() returns.
// This happens when the read has to be split in two since it's a circular buffer.
static inline void* cbuffer_readptr(cbuffer_t* buf, int offset, int* can_read_bytes)
{
	int a0 = buf->read + offset;
	if (a0 >= buf->size)
		a0 -= buf->size;
	if (can_read_bytes != NULL)
	{
		int c0 = buf->used;
		if (a0 + c0 > buf->size)
			c0 = buf->size - a0;

		*can_read_bytes = c0;
	}
	return buf->buf + a0;
}

// Copies given "count" bytes to the "dst" buffer without advancing the buffer read offset.
// Returns CBUFFER_SUCCESS on success or CBUFFER_NOMEM if count is more than available data.
static inline int cbuffer_copyto(cbuffer_t *buf, void *dst, int count, int offset) {
	
	if (count > cbuffer_get_used(buf))
		return CBUFFER_NOMEM;

	int can_read_bytes;
	void* src_ptr = cbuffer_readptr(buf, offset, &can_read_bytes);

	int c0 = (count < can_read_bytes) ? count : can_read_bytes;
	memcpy(dst, src_ptr, c0);
	
	int c1 = count - c0;

	if (c1 > 0)
		memcpy(((char *)dst) + c0, buf->buf, c1);

	return CBUFFER_SUCCESS;
}

typedef struct {
	cbuffer_t data_buffer;			// Circular Buffer for features
	int input_size;					// Number of bytes in each input chunk
} fixwin_t;

#ifdef _MSC_VER
static_assert(sizeof(fixwin_t) <= 64, "Data structure 'fixwin_t' is too big");
#endif

/*
* Try to dequeue a window.
*
* @param handle Pointer to an initialized handle.
* @param dst Pointer where to write window.
* @param stride_count Number of items (of size handle->input_size) to stride window.
* @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1) is no data is available.
*/
static inline int fixwin_dequeue(void* restrict handle, void* restrict dst, int count, int stride_count)
{
	fixwin_t* fep = (fixwin_t*)handle;

	const int stride_bytes = stride_count * fep->input_size;
	const int size = count * fep->input_size;
	if (cbuffer_get_used(&fep->data_buffer) >= size) {
		if (cbuffer_copyto(&fep->data_buffer, dst, size, 0) != 0)
			return IPWIN_RET_ERROR;

		if (cbuffer_advance(&fep->data_buffer, stride_bytes) != 0)
			return IPWIN_RET_ERROR;

		return IPWIN_RET_SUCCESS;
	}
	return IPWIN_RET_NODATA;
}

static void makeipt(int nw, int *ip)
{
    int j, l, m, m2, p, q;
    
    ip[2] = 0;
    ip[3] = 16;
    m = 2;
    for (l = nw; l > 32; l >>= 2) {
        m2 = m << 1;
        q = m2 << 3;
        for (j = m; j < m2; j++) {
            p = ip[j] << 2;
            ip[m + j] = p;
            ip[m2 + j] = p + q;
        }
        m = m2;
    }
}

static void makewt(int nw, int *ip, float *w)
{
    void makeipt(int nw, int *ip);
    int j, nwh, nw0, nw1;
    float delta, wn4r, wk1r, wk1i, wk3r, wk3i;
    
    ip[0] = nw;
    ip[1] = 1;
    if (nw > 2) {
        nwh = nw >> 1;
        delta = atan(1.0) / nwh;
        wn4r = cos(delta * nwh);
        w[0] = 1;
        w[1] = wn4r;
        if (nwh == 4) {
            w[2] = cos(delta * 2);
            w[3] = sin(delta * 2);
        } else if (nwh > 4) {
            makeipt(nw, ip);
            w[2] = 0.5 / cos(delta * 2);
            w[3] = 0.5 / cos(delta * 6);
            for (j = 4; j < nwh; j += 4) {
                w[j] = cos(delta * j);
                w[j + 1] = sin(delta * j);
                w[j + 2] = cos(3 * delta * j);
                w[j + 3] = -sin(3 * delta * j);
            }
        }
        nw0 = 0;
        while (nwh > 2) {
            nw1 = nw0 + nwh;
            nwh >>= 1;
            w[nw1] = 1;
            w[nw1 + 1] = wn4r;
            if (nwh == 4) {
                wk1r = w[nw0 + 4];
                wk1i = w[nw0 + 5];
                w[nw1 + 2] = wk1r;
                w[nw1 + 3] = wk1i;
            } else if (nwh > 4) {
                wk1r = w[nw0 + 4];
                wk3r = w[nw0 + 6];
                w[nw1 + 2] = 0.5 / wk1r;
                w[nw1 + 3] = 0.5 / wk3r;
                for (j = 4; j < nwh; j += 4) {
                    wk1r = w[nw0 + 2 * j];
                    wk1i = w[nw0 + 2 * j + 1];
                    wk3r = w[nw0 + 2 * j + 2];
                    wk3i = w[nw0 + 2 * j + 3];
                    w[nw1 + j] = wk1r;
                    w[nw1 + j + 1] = wk1i;
                    w[nw1 + j + 2] = wk3r;
                    w[nw1 + j + 3] = wk3i;
                }
            }
            nw0 = nw1;
        }
    }
}

static void makect(int nc, int *ip, float *c)
{
    int j, nch;
    float delta;
    
    ip[1] = nc;
    if (nc > 1) {
        nch = nc >> 1;
        delta = atan(1.0) / nch;
        c[0] = cos(delta * nch);
        c[nch] = 0.5 * c[0];
        for (j = 1; j < nch; j++) {
            c[j] = 0.5 * cos(delta * j);
            c[nc - j] = 0.5 * sin(delta * j);
        }
    }
}

static void bitrv2(int n, int *ip, float *a)
{
    int j, j1, k, k1, l, m, nh, nm;
    float xr, xi, yr, yi;
    
    m = 1;
    for (l = n >> 2; l > 8; l >>= 2) {
        m <<= 1;
    }
    nh = n >> 1;
    nm = 4 * m;
    if (l == 8) {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + 2 * ip[m + k];
                k1 = 4 * k + 2 * ip[m + j];
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + 2 * ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 += 2 * nm;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 -= nm;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= 2;
            k1 -= nh;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nh + 2;
            k1 += nh + 2;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= nh - nm;
            k1 += 2 * nm - 2;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
        }
    } else {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + ip[m + k];
                k1 = 4 * k + ip[m + j];
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 += nm;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
        }
    }
}

static void bitrv216(float *a)
{
    float x1r, x1i, x2r, x2i, x3r, x3i, x4r, x4i, 
        x5r, x5i, x7r, x7i, x8r, x8i, x10r, x10i, 
        x11r, x11i, x12r, x12i, x13r, x13i, x14r, x14i;
    
    x1r = a[2];
    x1i = a[3];
    x2r = a[4];
    x2i = a[5];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x5r = a[10];
    x5i = a[11];
    x7r = a[14];
    x7i = a[15];
    x8r = a[16];
    x8i = a[17];
    x10r = a[20];
    x10i = a[21];
    x11r = a[22];
    x11i = a[23];
    x12r = a[24];
    x12i = a[25];
    x13r = a[26];
    x13i = a[27];
    x14r = a[28];
    x14i = a[29];
    a[2] = x8r;
    a[3] = x8i;
    a[4] = x4r;
    a[5] = x4i;
    a[6] = x12r;
    a[7] = x12i;
    a[8] = x2r;
    a[9] = x2i;
    a[10] = x10r;
    a[11] = x10i;
    a[14] = x14r;
    a[15] = x14i;
    a[16] = x1r;
    a[17] = x1i;
    a[20] = x5r;
    a[21] = x5i;
    a[22] = x13r;
    a[23] = x13i;
    a[24] = x3r;
    a[25] = x3i;
    a[26] = x11r;
    a[27] = x11i;
    a[28] = x7r;
    a[29] = x7i;
}

static void bitrv208(float *a)
{
    float x1r, x1i, x3r, x3i, x4r, x4i, x6r, x6i;
    
    x1r = a[2];
    x1i = a[3];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x6r = a[12];
    x6i = a[13];
    a[2] = x4r;
    a[3] = x4i;
    a[6] = x6r;
    a[7] = x6i;
    a[8] = x1r;
    a[9] = x1i;
    a[12] = x3r;
    a[13] = x3i;
}

static void cftf1st(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, m, mh;
    float wn4r, csc1, csc3, wk1r, wk1i, wk3r, wk3i, 
        wd1r, wd1i, wd3r, wd3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i;
    
    mh = n >> 3;
    m = 2 * mh;
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] + a[j2];
    x0i = a[1] + a[j2 + 1];
    x1r = a[0] - a[j2];
    x1i = a[1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    a[j2] = x1r - x3i;
    a[j2 + 1] = x1i + x3r;
    a[j3] = x1r + x3i;
    a[j3 + 1] = x1i - x3r;
    wn4r = w[1];
    csc1 = w[2];
    csc3 = w[3];
    wd1r = 1;
    wd1i = 0;
    wd3r = 1;
    wd3i = 0;
    k = 0;
    for (j = 2; j < mh - 2; j += 4) {
        k += 4;
        wk1r = csc1 * (wd1r + w[k]);
        wk1i = csc1 * (wd1i + w[k + 1]);
        wk3r = csc3 * (wd3r + w[k + 2]);
        wk3i = csc3 * (wd3i + w[k + 3]);
        wd1r = w[k];
        wd1i = w[k + 1];
        wd3r = w[k + 2];
        wd3i = w[k + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] + a[j2];
        x0i = a[j + 1] + a[j2 + 1];
        x1r = a[j] - a[j2];
        x1i = a[j + 1] - a[j2 + 1];
        y0r = a[j + 2] + a[j2 + 2];
        y0i = a[j + 3] + a[j2 + 3];
        y1r = a[j + 2] - a[j2 + 2];
        y1i = a[j + 3] - a[j2 + 3];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 + 2] + a[j3 + 2];
        y2i = a[j1 + 3] + a[j3 + 3];
        y3r = a[j1 + 2] - a[j3 + 2];
        y3i = a[j1 + 3] - a[j3 + 3];
        a[j] = x0r + x2r;
        a[j + 1] = x0i + x2i;
        a[j + 2] = y0r + y2r;
        a[j + 3] = y0i + y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        a[j1 + 2] = y0r - y2r;
        a[j1 + 3] = y0i - y2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1r * x0r - wk1i * x0i;
        a[j2 + 1] = wk1r * x0i + wk1i * x0r;
        x0r = y1r - y3i;
        x0i = y1i + y3r;
        a[j2 + 2] = wd1r * x0r - wd1i * x0i;
        a[j2 + 3] = wd1r * x0i + wd1i * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3r * x0r + wk3i * x0i;
        a[j3 + 1] = wk3r * x0i - wk3i * x0r;
        x0r = y1r + y3i;
        x0i = y1i - y3r;
        a[j3 + 2] = wd3r * x0r + wd3i * x0i;
        a[j3 + 3] = wd3r * x0i - wd3i * x0r;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] + a[j2];
        x0i = a[j0 + 1] + a[j2 + 1];
        x1r = a[j0] - a[j2];
        x1i = a[j0 + 1] - a[j2 + 1];
        y0r = a[j0 - 2] + a[j2 - 2];
        y0i = a[j0 - 1] + a[j2 - 1];
        y1r = a[j0 - 2] - a[j2 - 2];
        y1i = a[j0 - 1] - a[j2 - 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 - 2] + a[j3 - 2];
        y2i = a[j1 - 1] + a[j3 - 1];
        y3r = a[j1 - 2] - a[j3 - 2];
        y3i = a[j1 - 1] - a[j3 - 1];
        a[j0] = x0r + x2r;
        a[j0 + 1] = x0i + x2i;
        a[j0 - 2] = y0r + y2r;
        a[j0 - 1] = y0i + y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        a[j1 - 2] = y0r - y2r;
        a[j1 - 1] = y0i - y2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1i * x0r - wk1r * x0i;
        a[j2 + 1] = wk1i * x0i + wk1r * x0r;
        x0r = y1r - y3i;
        x0i = y1i + y3r;
        a[j2 - 2] = wd1i * x0r - wd1r * x0i;
        a[j2 - 1] = wd1i * x0i + wd1r * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3i * x0r + wk3r * x0i;
        a[j3 + 1] = wk3i * x0i - wk3r * x0r;
        x0r = y1r + y3i;
        x0i = y1i - y3r;
        a[j3 - 2] = wd3i * x0r + wd3r * x0i;
        a[j3 - 1] = wd3i * x0i - wd3r * x0r;
    }
    wk1r = csc1 * (wd1r + wn4r);
    wk1i = csc1 * (wd1i + wn4r);
    wk3r = csc3 * (wd3r - wn4r);
    wk3i = csc3 * (wd3i - wn4r);
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0 - 2] + a[j2 - 2];
    x0i = a[j0 - 1] + a[j2 - 1];
    x1r = a[j0 - 2] - a[j2 - 2];
    x1i = a[j0 - 1] - a[j2 - 1];
    x2r = a[j1 - 2] + a[j3 - 2];
    x2i = a[j1 - 1] + a[j3 - 1];
    x3r = a[j1 - 2] - a[j3 - 2];
    x3i = a[j1 - 1] - a[j3 - 1];
    a[j0 - 2] = x0r + x2r;
    a[j0 - 1] = x0i + x2i;
    a[j1 - 2] = x0r - x2r;
    a[j1 - 1] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2 - 2] = wk1r * x0r - wk1i * x0i;
    a[j2 - 1] = wk1r * x0i + wk1i * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3 - 2] = wk3r * x0r + wk3i * x0i;
    a[j3 - 1] = wk3r * x0i - wk3i * x0r;
    x0r = a[j0] + a[j2];
    x0i = a[j0 + 1] + a[j2 + 1];
    x1r = a[j0] - a[j2];
    x1i = a[j0 + 1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[j0] = x0r + x2r;
    a[j0 + 1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2] = wn4r * (x0r - x0i);
    a[j2 + 1] = wn4r * (x0i + x0r);
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3] = -wn4r * (x0r + x0i);
    a[j3 + 1] = -wn4r * (x0i - x0r);
    x0r = a[j0 + 2] + a[j2 + 2];
    x0i = a[j0 + 3] + a[j2 + 3];
    x1r = a[j0 + 2] - a[j2 + 2];
    x1i = a[j0 + 3] - a[j2 + 3];
    x2r = a[j1 + 2] + a[j3 + 2];
    x2i = a[j1 + 3] + a[j3 + 3];
    x3r = a[j1 + 2] - a[j3 + 2];
    x3i = a[j1 + 3] - a[j3 + 3];
    a[j0 + 2] = x0r + x2r;
    a[j0 + 3] = x0i + x2i;
    a[j1 + 2] = x0r - x2r;
    a[j1 + 3] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2 + 2] = wk1i * x0r - wk1r * x0i;
    a[j2 + 3] = wk1i * x0i + wk1r * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3 + 2] = wk3i * x0r + wk3r * x0i;
    a[j3 + 3] = wk3i * x0i - wk3r * x0r;
}

static void cftmdl1(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, m, mh;
    float wn4r, wk1r, wk1i, wk3r, wk3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i;
    
    mh = n >> 3;
    m = 2 * mh;
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] + a[j2];
    x0i = a[1] + a[j2 + 1];
    x1r = a[0] - a[j2];
    x1i = a[1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    a[j2] = x1r - x3i;
    a[j2 + 1] = x1i + x3r;
    a[j3] = x1r + x3i;
    a[j3 + 1] = x1i - x3r;
    wn4r = w[1];
    k = 0;
    for (j = 2; j < mh; j += 2) {
        k += 4;
        wk1r = w[k];
        wk1i = w[k + 1];
        wk3r = w[k + 2];
        wk3i = w[k + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] + a[j2];
        x0i = a[j + 1] + a[j2 + 1];
        x1r = a[j] - a[j2];
        x1i = a[j + 1] - a[j2 + 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        a[j] = x0r + x2r;
        a[j + 1] = x0i + x2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1r * x0r - wk1i * x0i;
        a[j2 + 1] = wk1r * x0i + wk1i * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3r * x0r + wk3i * x0i;
        a[j3 + 1] = wk3r * x0i - wk3i * x0r;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] + a[j2];
        x0i = a[j0 + 1] + a[j2 + 1];
        x1r = a[j0] - a[j2];
        x1i = a[j0 + 1] - a[j2 + 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        a[j0] = x0r + x2r;
        a[j0 + 1] = x0i + x2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1i * x0r - wk1r * x0i;
        a[j2 + 1] = wk1i * x0i + wk1r * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3i * x0r + wk3r * x0i;
        a[j3 + 1] = wk3i * x0i - wk3r * x0r;
    }
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0] + a[j2];
    x0i = a[j0 + 1] + a[j2 + 1];
    x1r = a[j0] - a[j2];
    x1i = a[j0 + 1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[j0] = x0r + x2r;
    a[j0 + 1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2] = wn4r * (x0r - x0i);
    a[j2 + 1] = wn4r * (x0i + x0r);
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3] = -wn4r * (x0r + x0i);
    a[j3 + 1] = -wn4r * (x0i - x0r);
}

static void cftmdl2(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, kr, m, mh;
    float wn4r, wk1r, wk1i, wk3r, wk3i, wd1r, wd1i, wd3r, wd3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, y0r, y0i, y2r, y2i;
    
    mh = n >> 3;
    m = 2 * mh;
    wn4r = w[1];
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] - a[j2 + 1];
    x0i = a[1] + a[j2];
    x1r = a[0] + a[j2 + 1];
    x1i = a[1] - a[j2];
    x2r = a[j1] - a[j3 + 1];
    x2i = a[j1 + 1] + a[j3];
    x3r = a[j1] + a[j3 + 1];
    x3i = a[j1 + 1] - a[j3];
    y0r = wn4r * (x2r - x2i);
    y0i = wn4r * (x2i + x2r);
    a[0] = x0r + y0r;
    a[1] = x0i + y0i;
    a[j1] = x0r - y0r;
    a[j1 + 1] = x0i - y0i;
    y0r = wn4r * (x3r - x3i);
    y0i = wn4r * (x3i + x3r);
    a[j2] = x1r - y0i;
    a[j2 + 1] = x1i + y0r;
    a[j3] = x1r + y0i;
    a[j3 + 1] = x1i - y0r;
    k = 0;
    kr = 2 * m;
    for (j = 2; j < mh; j += 2) {
        k += 4;
        wk1r = w[k];
        wk1i = w[k + 1];
        wk3r = w[k + 2];
        wk3i = w[k + 3];
        kr -= 4;
        wd1i = w[kr];
        wd1r = w[kr + 1];
        wd3i = w[kr + 2];
        wd3r = w[kr + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] - a[j2 + 1];
        x0i = a[j + 1] + a[j2];
        x1r = a[j] + a[j2 + 1];
        x1i = a[j + 1] - a[j2];
        x2r = a[j1] - a[j3 + 1];
        x2i = a[j1 + 1] + a[j3];
        x3r = a[j1] + a[j3 + 1];
        x3i = a[j1 + 1] - a[j3];
        y0r = wk1r * x0r - wk1i * x0i;
        y0i = wk1r * x0i + wk1i * x0r;
        y2r = wd1r * x2r - wd1i * x2i;
        y2i = wd1r * x2i + wd1i * x2r;
        a[j] = y0r + y2r;
        a[j + 1] = y0i + y2i;
        a[j1] = y0r - y2r;
        a[j1 + 1] = y0i - y2i;
        y0r = wk3r * x1r + wk3i * x1i;
        y0i = wk3r * x1i - wk3i * x1r;
        y2r = wd3r * x3r + wd3i * x3i;
        y2i = wd3r * x3i - wd3i * x3r;
        a[j2] = y0r + y2r;
        a[j2 + 1] = y0i + y2i;
        a[j3] = y0r - y2r;
        a[j3 + 1] = y0i - y2i;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] - a[j2 + 1];
        x0i = a[j0 + 1] + a[j2];
        x1r = a[j0] + a[j2 + 1];
        x1i = a[j0 + 1] - a[j2];
        x2r = a[j1] - a[j3 + 1];
        x2i = a[j1 + 1] + a[j3];
        x3r = a[j1] + a[j3 + 1];
        x3i = a[j1 + 1] - a[j3];
        y0r = wd1i * x0r - wd1r * x0i;
        y0i = wd1i * x0i + wd1r * x0r;
        y2r = wk1i * x2r - wk1r * x2i;
        y2i = wk1i * x2i + wk1r * x2r;
        a[j0] = y0r + y2r;
        a[j0 + 1] = y0i + y2i;
        a[j1] = y0r - y2r;
        a[j1 + 1] = y0i - y2i;
        y0r = wd3i * x1r + wd3r * x1i;
        y0i = wd3i * x1i - wd3r * x1r;
        y2r = wk3i * x3r + wk3r * x3i;
        y2i = wk3i * x3i - wk3r * x3r;
        a[j2] = y0r + y2r;
        a[j2 + 1] = y0i + y2i;
        a[j3] = y0r - y2r;
        a[j3 + 1] = y0i - y2i;
    }
    wk1r = w[m];
    wk1i = w[m + 1];
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0] - a[j2 + 1];
    x0i = a[j0 + 1] + a[j2];
    x1r = a[j0] + a[j2 + 1];
    x1i = a[j0 + 1] - a[j2];
    x2r = a[j1] - a[j3 + 1];
    x2i = a[j1 + 1] + a[j3];
    x3r = a[j1] + a[j3 + 1];
    x3i = a[j1 + 1] - a[j3];
    y0r = wk1r * x0r - wk1i * x0i;
    y0i = wk1r * x0i + wk1i * x0r;
    y2r = wk1i * x2r - wk1r * x2i;
    y2i = wk1i * x2i + wk1r * x2r;
    a[j0] = y0r + y2r;
    a[j0 + 1] = y0i + y2i;
    a[j1] = y0r - y2r;
    a[j1 + 1] = y0i - y2i;
    y0r = wk1i * x1r - wk1r * x1i;
    y0i = wk1i * x1i + wk1r * x1r;
    y2r = wk1r * x3r - wk1i * x3i;
    y2i = wk1r * x3i + wk1i * x3r;
    a[j2] = y0r - y2r;
    a[j2 + 1] = y0i - y2i;
    a[j3] = y0r + y2r;
    a[j3 + 1] = y0i + y2i;
}

static int cfttree(int n, int j, int k, float *a, int nw, float *w)
{
    void cftmdl1(int n, float *a, float *w);
    void cftmdl2(int n, float *a, float *w);
    int i, isplt, m;
    
    if ((k & 3) != 0) {
        isplt = k & 1;
        if (isplt != 0) {
            cftmdl1(n, &a[j - n], &w[nw - (n >> 1)]);
        } else {
            cftmdl2(n, &a[j - n], &w[nw - n]);
        }
    } else {
        m = n;
        for (i = k; (i & 3) == 0; i >>= 2) {
            m <<= 2;
        }
        isplt = i & 1;
        if (isplt != 0) {
            while (m > 128) {
                cftmdl1(m, &a[j - m], &w[nw - (m >> 1)]);
                m >>= 2;
            }
        } else {
            while (m > 128) {
                cftmdl2(m, &a[j - m], &w[nw - m]);
                m >>= 2;
            }
        }
    }
    return isplt;
}

static void cftf161(float *a, float *w)
{
    float wn4r, wk1r, wk1i, 
        x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i, 
        y8r, y8i, y9r, y9i, y10r, y10i, y11r, y11i, 
        y12r, y12i, y13r, y13i, y14r, y14i, y15r, y15i;
    
    wn4r = w[1];
    wk1r = w[2];
    wk1i = w[3];
    x0r = a[0] + a[16];
    x0i = a[1] + a[17];
    x1r = a[0] - a[16];
    x1i = a[1] - a[17];
    x2r = a[8] + a[24];
    x2i = a[9] + a[25];
    x3r = a[8] - a[24];
    x3i = a[9] - a[25];
    y0r = x0r + x2r;
    y0i = x0i + x2i;
    y4r = x0r - x2r;
    y4i = x0i - x2i;
    y8r = x1r - x3i;
    y8i = x1i + x3r;
    y12r = x1r + x3i;
    y12i = x1i - x3r;
    x0r = a[2] + a[18];
    x0i = a[3] + a[19];
    x1r = a[2] - a[18];
    x1i = a[3] - a[19];
    x2r = a[10] + a[26];
    x2i = a[11] + a[27];
    x3r = a[10] - a[26];
    x3i = a[11] - a[27];
    y1r = x0r + x2r;
    y1i = x0i + x2i;
    y5r = x0r - x2r;
    y5i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    y9r = wk1r * x0r - wk1i * x0i;
    y9i = wk1r * x0i + wk1i * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    y13r = wk1i * x0r - wk1r * x0i;
    y13i = wk1i * x0i + wk1r * x0r;
    x0r = a[4] + a[20];
    x0i = a[5] + a[21];
    x1r = a[4] - a[20];
    x1i = a[5] - a[21];
    x2r = a[12] + a[28];
    x2i = a[13] + a[29];
    x3r = a[12] - a[28];
    x3i = a[13] - a[29];
    y2r = x0r + x2r;
    y2i = x0i + x2i;
    y6r = x0r - x2r;
    y6i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    y10r = wn4r * (x0r - x0i);
    y10i = wn4r * (x0i + x0r);
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    y14r = wn4r * (x0r + x0i);
    y14i = wn4r * (x0i - x0r);
    x0r = a[6] + a[22];
    x0i = a[7] + a[23];
    x1r = a[6] - a[22];
    x1i = a[7] - a[23];
    x2r = a[14] + a[30];
    x2i = a[15] + a[31];
    x3r = a[14] - a[30];
    x3i = a[15] - a[31];
    y3r = x0r + x2r;
    y3i = x0i + x2i;
    y7r = x0r - x2r;
    y7i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    y11r = wk1i * x0r - wk1r * x0i;
    y11i = wk1i * x0i + wk1r * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    y15r = wk1r * x0r - wk1i * x0i;
    y15i = wk1r * x0i + wk1i * x0r;
    x0r = y12r - y14r;
    x0i = y12i - y14i;
    x1r = y12r + y14r;
    x1i = y12i + y14i;
    x2r = y13r - y15r;
    x2i = y13i - y15i;
    x3r = y13r + y15r;
    x3i = y13i + y15i;
    a[24] = x0r + x2r;
    a[25] = x0i + x2i;
    a[26] = x0r - x2r;
    a[27] = x0i - x2i;
    a[28] = x1r - x3i;
    a[29] = x1i + x3r;
    a[30] = x1r + x3i;
    a[31] = x1i - x3r;
    x0r = y8r + y10r;
    x0i = y8i + y10i;
    x1r = y8r - y10r;
    x1i = y8i - y10i;
    x2r = y9r + y11r;
    x2i = y9i + y11i;
    x3r = y9r - y11r;
    x3i = y9i - y11i;
    a[16] = x0r + x2r;
    a[17] = x0i + x2i;
    a[18] = x0r - x2r;
    a[19] = x0i - x2i;
    a[20] = x1r - x3i;
    a[21] = x1i + x3r;
    a[22] = x1r + x3i;
    a[23] = x1i - x3r;
    x0r = y5r - y7i;
    x0i = y5i + y7r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    x0r = y5r + y7i;
    x0i = y5i - y7r;
    x3r = wn4r * (x0r - x0i);
    x3i = wn4r * (x0i + x0r);
    x0r = y4r - y6i;
    x0i = y4i + y6r;
    x1r = y4r + y6i;
    x1i = y4i - y6r;
    a[8] = x0r + x2r;
    a[9] = x0i + x2i;
    a[10] = x0r - x2r;
    a[11] = x0i - x2i;
    a[12] = x1r - x3i;
    a[13] = x1i + x3r;
    a[14] = x1r + x3i;
    a[15] = x1i - x3r;
    x0r = y0r + y2r;
    x0i = y0i + y2i;
    x1r = y0r - y2r;
    x1i = y0i - y2i;
    x2r = y1r + y3r;
    x2i = y1i + y3i;
    x3r = y1r - y3r;
    x3i = y1i - y3i;
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[2] = x0r - x2r;
    a[3] = x0i - x2i;
    a[4] = x1r - x3i;
    a[5] = x1i + x3r;
    a[6] = x1r + x3i;
    a[7] = x1i - x3r;
}

static void cftf162(float *a, float *w)
{
    float wn4r, wk1r, wk1i, wk2r, wk2i, wk3r, wk3i, 
        x0r, x0i, x1r, x1i, x2r, x2i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i, 
        y8r, y8i, y9r, y9i, y10r, y10i, y11r, y11i, 
        y12r, y12i, y13r, y13i, y14r, y14i, y15r, y15i;
    
    wn4r = w[1];
    wk1r = w[4];
    wk1i = w[5];
    wk3r = w[6];
    wk3i = -w[7];
    wk2r = w[8];
    wk2i = w[9];
    x1r = a[0] - a[17];
    x1i = a[1] + a[16];
    x0r = a[8] - a[25];
    x0i = a[9] + a[24];
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    y0r = x1r + x2r;
    y0i = x1i + x2i;
    y4r = x1r - x2r;
    y4i = x1i - x2i;
    x1r = a[0] + a[17];
    x1i = a[1] - a[16];
    x0r = a[8] + a[25];
    x0i = a[9] - a[24];
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    y8r = x1r - x2i;
    y8i = x1i + x2r;
    y12r = x1r + x2i;
    y12i = x1i - x2r;
    x0r = a[2] - a[19];
    x0i = a[3] + a[18];
    x1r = wk1r * x0r - wk1i * x0i;
    x1i = wk1r * x0i + wk1i * x0r;
    x0r = a[10] - a[27];
    x0i = a[11] + a[26];
    x2r = wk3i * x0r - wk3r * x0i;
    x2i = wk3i * x0i + wk3r * x0r;
    y1r = x1r + x2r;
    y1i = x1i + x2i;
    y5r = x1r - x2r;
    y5i = x1i - x2i;
    x0r = a[2] + a[19];
    x0i = a[3] - a[18];
    x1r = wk3r * x0r - wk3i * x0i;
    x1i = wk3r * x0i + wk3i * x0r;
    x0r = a[10] + a[27];
    x0i = a[11] - a[26];
    x2r = wk1r * x0r + wk1i * x0i;
    x2i = wk1r * x0i - wk1i * x0r;
    y9r = x1r - x2r;
    y9i = x1i - x2i;
    y13r = x1r + x2r;
    y13i = x1i + x2i;
    x0r = a[4] - a[21];
    x0i = a[5] + a[20];
    x1r = wk2r * x0r - wk2i * x0i;
    x1i = wk2r * x0i + wk2i * x0r;
    x0r = a[12] - a[29];
    x0i = a[13] + a[28];
    x2r = wk2i * x0r - wk2r * x0i;
    x2i = wk2i * x0i + wk2r * x0r;
    y2r = x1r + x2r;
    y2i = x1i + x2i;
    y6r = x1r - x2r;
    y6i = x1i - x2i;
    x0r = a[4] + a[21];
    x0i = a[5] - a[20];
    x1r = wk2i * x0r - wk2r * x0i;
    x1i = wk2i * x0i + wk2r * x0r;
    x0r = a[12] + a[29];
    x0i = a[13] - a[28];
    x2r = wk2r * x0r - wk2i * x0i;
    x2i = wk2r * x0i + wk2i * x0r;
    y10r = x1r - x2r;
    y10i = x1i - x2i;
    y14r = x1r + x2r;
    y14i = x1i + x2i;
    x0r = a[6] - a[23];
    x0i = a[7] + a[22];
    x1r = wk3r * x0r - wk3i * x0i;
    x1i = wk3r * x0i + wk3i * x0r;
    x0r = a[14] - a[31];
    x0i = a[15] + a[30];
    x2r = wk1i * x0r - wk1r * x0i;
    x2i = wk1i * x0i + wk1r * x0r;
    y3r = x1r + x2r;
    y3i = x1i + x2i;
    y7r = x1r - x2r;
    y7i = x1i - x2i;
    x0r = a[6] + a[23];
    x0i = a[7] - a[22];
    x1r = wk1i * x0r + wk1r * x0i;
    x1i = wk1i * x0i - wk1r * x0r;
    x0r = a[14] + a[31];
    x0i = a[15] - a[30];
    x2r = wk3i * x0r - wk3r * x0i;
    x2i = wk3i * x0i + wk3r * x0r;
    y11r = x1r + x2r;
    y11i = x1i + x2i;
    y15r = x1r - x2r;
    y15i = x1i - x2i;
    x1r = y0r + y2r;
    x1i = y0i + y2i;
    x2r = y1r + y3r;
    x2i = y1i + y3i;
    a[0] = x1r + x2r;
    a[1] = x1i + x2i;
    a[2] = x1r - x2r;
    a[3] = x1i - x2i;
    x1r = y0r - y2r;
    x1i = y0i - y2i;
    x2r = y1r - y3r;
    x2i = y1i - y3i;
    a[4] = x1r - x2i;
    a[5] = x1i + x2r;
    a[6] = x1r + x2i;
    a[7] = x1i - x2r;
    x1r = y4r - y6i;
    x1i = y4i + y6r;
    x0r = y5r - y7i;
    x0i = y5i + y7r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[8] = x1r + x2r;
    a[9] = x1i + x2i;
    a[10] = x1r - x2r;
    a[11] = x1i - x2i;
    x1r = y4r + y6i;
    x1i = y4i - y6r;
    x0r = y5r + y7i;
    x0i = y5i - y7r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[12] = x1r - x2i;
    a[13] = x1i + x2r;
    a[14] = x1r + x2i;
    a[15] = x1i - x2r;
    x1r = y8r + y10r;
    x1i = y8i + y10i;
    x2r = y9r - y11r;
    x2i = y9i - y11i;
    a[16] = x1r + x2r;
    a[17] = x1i + x2i;
    a[18] = x1r - x2r;
    a[19] = x1i - x2i;
    x1r = y8r - y10r;
    x1i = y8i - y10i;
    x2r = y9r + y11r;
    x2i = y9i + y11i;
    a[20] = x1r - x2i;
    a[21] = x1i + x2r;
    a[22] = x1r + x2i;
    a[23] = x1i - x2r;
    x1r = y12r - y14i;
    x1i = y12i + y14r;
    x0r = y13r + y15i;
    x0i = y13i - y15r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[24] = x1r + x2r;
    a[25] = x1i + x2i;
    a[26] = x1r - x2r;
    a[27] = x1i - x2i;
    x1r = y12r + y14i;
    x1i = y12i - y14r;
    x0r = y13r - y15i;
    x0i = y13i + y15r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[28] = x1r - x2i;
    a[29] = x1i + x2r;
    a[30] = x1r + x2i;
    a[31] = x1i - x2r;
}

static void cftf081(float *a, float *w)
{
    float wn4r, x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i;
    
    wn4r = w[1];
    x0r = a[0] + a[8];
    x0i = a[1] + a[9];
    x1r = a[0] - a[8];
    x1i = a[1] - a[9];
    x2r = a[4] + a[12];
    x2i = a[5] + a[13];
    x3r = a[4] - a[12];
    x3i = a[5] - a[13];
    y0r = x0r + x2r;
    y0i = x0i + x2i;
    y2r = x0r - x2r;
    y2i = x0i - x2i;
    y1r = x1r - x3i;
    y1i = x1i + x3r;
    y3r = x1r + x3i;
    y3i = x1i - x3r;
    x0r = a[2] + a[10];
    x0i = a[3] + a[11];
    x1r = a[2] - a[10];
    x1i = a[3] - a[11];
    x2r = a[6] + a[14];
    x2i = a[7] + a[15];
    x3r = a[6] - a[14];
    x3i = a[7] - a[15];
    y4r = x0r + x2r;
    y4i = x0i + x2i;
    y6r = x0r - x2r;
    y6i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    x2r = x1r + x3i;
    x2i = x1i - x3r;
    y5r = wn4r * (x0r - x0i);
    y5i = wn4r * (x0r + x0i);
    y7r = wn4r * (x2r - x2i);
    y7i = wn4r * (x2r + x2i);
    a[8] = y1r + y5r;
    a[9] = y1i + y5i;
    a[10] = y1r - y5r;
    a[11] = y1i - y5i;
    a[12] = y3r - y7i;
    a[13] = y3i + y7r;
    a[14] = y3r + y7i;
    a[15] = y3i - y7r;
    a[0] = y0r + y4r;
    a[1] = y0i + y4i;
    a[2] = y0r - y4r;
    a[3] = y0i - y4i;
    a[4] = y2r - y6i;
    a[5] = y2i + y6r;
    a[6] = y2r + y6i;
    a[7] = y2i - y6r;
}

static void cftf082(float *a, float *w)
{
    float wn4r, wk1r, wk1i, x0r, x0i, x1r, x1i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i;
    
    wn4r = w[1];
    wk1r = w[2];
    wk1i = w[3];
    y0r = a[0] - a[9];
    y0i = a[1] + a[8];
    y1r = a[0] + a[9];
    y1i = a[1] - a[8];
    x0r = a[4] - a[13];
    x0i = a[5] + a[12];
    y2r = wn4r * (x0r - x0i);
    y2i = wn4r * (x0i + x0r);
    x0r = a[4] + a[13];
    x0i = a[5] - a[12];
    y3r = wn4r * (x0r - x0i);
    y3i = wn4r * (x0i + x0r);
    x0r = a[2] - a[11];
    x0i = a[3] + a[10];
    y4r = wk1r * x0r - wk1i * x0i;
    y4i = wk1r * x0i + wk1i * x0r;
    x0r = a[2] + a[11];
    x0i = a[3] - a[10];
    y5r = wk1i * x0r - wk1r * x0i;
    y5i = wk1i * x0i + wk1r * x0r;
    x0r = a[6] - a[15];
    x0i = a[7] + a[14];
    y6r = wk1i * x0r - wk1r * x0i;
    y6i = wk1i * x0i + wk1r * x0r;
    x0r = a[6] + a[15];
    x0i = a[7] - a[14];
    y7r = wk1r * x0r - wk1i * x0i;
    y7i = wk1r * x0i + wk1i * x0r;
    x0r = y0r + y2r;
    x0i = y0i + y2i;
    x1r = y4r + y6r;
    x1i = y4i + y6i;
    a[0] = x0r + x1r;
    a[1] = x0i + x1i;
    a[2] = x0r - x1r;
    a[3] = x0i - x1i;
    x0r = y0r - y2r;
    x0i = y0i - y2i;
    x1r = y4r - y6r;
    x1i = y4i - y6i;
    a[4] = x0r - x1i;
    a[5] = x0i + x1r;
    a[6] = x0r + x1i;
    a[7] = x0i - x1r;
    x0r = y1r - y3i;
    x0i = y1i + y3r;
    x1r = y5r - y7r;
    x1i = y5i - y7i;
    a[8] = x0r + x1r;
    a[9] = x0i + x1i;
    a[10] = x0r - x1r;
    a[11] = x0i - x1i;
    x0r = y1r + y3i;
    x0i = y1i - y3r;
    x1r = y5r + y7r;
    x1i = y5i + y7i;
    a[12] = x0r - x1i;
    a[13] = x0i + x1r;
    a[14] = x0r + x1i;
    a[15] = x0i - x1r;
}

static void cftleaf(int n, int isplt, float *a, int nw, float *w)
{
    void cftmdl1(int n, float *a, float *w);
    void cftmdl2(int n, float *a, float *w);
    void cftf161(float *a, float *w);
    void cftf162(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftf082(float *a, float *w);
    
    if (n == 512) {
        cftmdl1(128, a, &w[nw - 64]);
        cftf161(a, &w[nw - 8]);
        cftf162(&a[32], &w[nw - 32]);
        cftf161(&a[64], &w[nw - 8]);
        cftf161(&a[96], &w[nw - 8]);
        cftmdl2(128, &a[128], &w[nw - 128]);
        cftf161(&a[128], &w[nw - 8]);
        cftf162(&a[160], &w[nw - 32]);
        cftf161(&a[192], &w[nw - 8]);
        cftf162(&a[224], &w[nw - 32]);
        cftmdl1(128, &a[256], &w[nw - 64]);
        cftf161(&a[256], &w[nw - 8]);
        cftf162(&a[288], &w[nw - 32]);
        cftf161(&a[320], &w[nw - 8]);
        cftf161(&a[352], &w[nw - 8]);
        if (isplt != 0) {
            cftmdl1(128, &a[384], &w[nw - 64]);
            cftf161(&a[480], &w[nw - 8]);
        } else {
            cftmdl2(128, &a[384], &w[nw - 128]);
            cftf162(&a[480], &w[nw - 32]);
        }
        cftf161(&a[384], &w[nw - 8]);
        cftf162(&a[416], &w[nw - 32]);
        cftf161(&a[448], &w[nw - 8]);
    } else {
        cftmdl1(64, a, &w[nw - 32]);
        cftf081(a, &w[nw - 8]);
        cftf082(&a[16], &w[nw - 8]);
        cftf081(&a[32], &w[nw - 8]);
        cftf081(&a[48], &w[nw - 8]);
        cftmdl2(64, &a[64], &w[nw - 64]);
        cftf081(&a[64], &w[nw - 8]);
        cftf082(&a[80], &w[nw - 8]);
        cftf081(&a[96], &w[nw - 8]);
        cftf082(&a[112], &w[nw - 8]);
        cftmdl1(64, &a[128], &w[nw - 32]);
        cftf081(&a[128], &w[nw - 8]);
        cftf082(&a[144], &w[nw - 8]);
        cftf081(&a[160], &w[nw - 8]);
        cftf081(&a[176], &w[nw - 8]);
        if (isplt != 0) {
            cftmdl1(64, &a[192], &w[nw - 32]);
            cftf081(&a[240], &w[nw - 8]);
        } else {
            cftmdl2(64, &a[192], &w[nw - 64]);
            cftf082(&a[240], &w[nw - 8]);
        }
        cftf081(&a[192], &w[nw - 8]);
        cftf082(&a[208], &w[nw - 8]);
        cftf081(&a[224], &w[nw - 8]);
    }
}

static void cftrec4(int n, float *a, int nw, float *w)
{
    int cfttree(int n, int j, int k, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftmdl1(int n, float *a, float *w);
    int isplt, j, k, m;
    
    m = n;
    while (m > 512) {
        m >>= 2;
        cftmdl1(m, &a[n - m], &w[nw - (m >> 1)]);
    }
    cftleaf(m, 1, &a[n - m], nw, w);
    k = 0;
    for (j = n - m; j > 0; j -= m) {
        k++;
        isplt = cfttree(m, j, k, a, nw, w);
        cftleaf(m, isplt, &a[j - m], nw, w);
    }
}

static void cftfx41(int n, float *a, int nw, float *w)
{
    void cftf161(float *a, float *w);
    void cftf162(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftf082(float *a, float *w);
    
    if (n == 128) {
        cftf161(a, &w[nw - 8]);
        cftf162(&a[32], &w[nw - 32]);
        cftf161(&a[64], &w[nw - 8]);
        cftf161(&a[96], &w[nw - 8]);
    } else {
        cftf081(a, &w[nw - 8]);
        cftf082(&a[16], &w[nw - 8]);
        cftf081(&a[32], &w[nw - 8]);
        cftf081(&a[48], &w[nw - 8]);
    }
}

static void cftf040(float *a)
{
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i;
    
    x0r = a[0] + a[4];
    x0i = a[1] + a[5];
    x1r = a[0] - a[4];
    x1i = a[1] - a[5];
    x2r = a[2] + a[6];
    x2i = a[3] + a[7];
    x3r = a[2] - a[6];
    x3i = a[3] - a[7];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[2] = x1r - x3i;
    a[3] = x1i + x3r;
    a[4] = x0r - x2r;
    a[5] = x0i - x2i;
    a[6] = x1r + x3i;
    a[7] = x1i - x3r;
}

static void cftx020(float *a)
{
    float x0r, x0i;
    
    x0r = a[0] - a[2];
    x0i = a[1] - a[3];
    a[0] += a[2];
    a[1] += a[3];
    a[2] = x0r;
    a[3] = x0i;
}

#ifdef USE_CDFT_THREADS
struct cdft_arg_st {
    int n0;
    int n;
    float *a;
    int nw;
    float *w;
};
typedef struct cdft_arg_st cdft_arg_t;


static void cftrec4_th(int n, float *a, int nw, float *w)
{
    void *cftrec1_th(void *p);
    void *cftrec2_th(void *p);
    int i, idiv4, m, nthread;
    cdft_thread_t th[4];
    cdft_arg_t ag[4];
    
    nthread = 2;
    idiv4 = 0;
    m = n >> 1;
    if (n > CDFT_4THREADS_BEGIN_N) {
        nthread = 4;
        idiv4 = 1;
        m >>= 1;
    }
    for (i = 0; i < nthread; i++) {
        ag[i].n0 = n;
        ag[i].n = m;
        ag[i].a = &a[i * m];
        ag[i].nw = nw;
        ag[i].w = w;
        if (i != idiv4) {
            cdft_thread_create(&th[i], cftrec1_th, &ag[i]);
        } else {
            cdft_thread_create(&th[i], cftrec2_th, &ag[i]);
        }
    }
    for (i = 0; i < nthread; i++) {
        cdft_thread_wait(th[i]);
    }
}


static void *cftrec1_th(void *p)
{
    int cfttree(int n, int j, int k, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftmdl1(int n, float *a, float *w);
    int isplt, j, k, m, n, n0, nw;
    float *a, *w;
    
    n0 = ((cdft_arg_t *) p)->n0;
    n = ((cdft_arg_t *) p)->n;
    a = ((cdft_arg_t *) p)->a;
    nw = ((cdft_arg_t *) p)->nw;
    w = ((cdft_arg_t *) p)->w;
    m = n0;
    while (m > 512) {
        m >>= 2;
        cftmdl1(m, &a[n - m], &w[nw - (m >> 1)]);
    }
    cftleaf(m, 1, &a[n - m], nw, w);
    k = 0;
    for (j = n - m; j > 0; j -= m) {
        k++;
        isplt = cfttree(m, j, k, a, nw, w);
        cftleaf(m, isplt, &a[j - m], nw, w);
    }
    return (void *) 0;
}


static void *cftrec2_th(void *p)
{
    int cfttree(int n, int j, int k, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftmdl2(int n, float *a, float *w);
    int isplt, j, k, m, n, n0, nw;
    float *a, *w;
    
    n0 = ((cdft_arg_t *) p)->n0;
    n = ((cdft_arg_t *) p)->n;
    a = ((cdft_arg_t *) p)->a;
    nw = ((cdft_arg_t *) p)->nw;
    w = ((cdft_arg_t *) p)->w;
    k = 1;
    m = n0;
    while (m > 512) {
        m >>= 2;
        k <<= 2;
        cftmdl2(m, &a[n - m], &w[nw - m]);
    }
    cftleaf(m, 0, &a[n - m], nw, w);
    k >>= 1;
    for (j = n - m; j > 0; j -= m) {
        k++;
        isplt = cfttree(m, j, k, a, nw, w);
        cftleaf(m, isplt, &a[j - m], nw, w);
    }
    return (void *) 0;
}
#endif /* USE_CDFT_THREADS */

static void cftfsub(int n, float *a, int *ip, int nw, float *w)
{
    void bitrv2(int n, int *ip, float *a);
    void bitrv216(float *a);
    void bitrv208(float *a);
    void cftf1st(int n, float *a, float *w);
    void cftrec4(int n, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftfx41(int n, float *a, int nw, float *w);
    void cftf161(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftf040(float *a);
    void cftx020(float *a);
#ifdef USE_CDFT_THREADS
    void cftrec4_th(int n, float *a, int nw, float *w);
#endif /* USE_CDFT_THREADS */
    
    if (n > 8) {
        if (n > 32) {
            cftf1st(n, a, &w[nw - (n >> 2)]);
#ifdef USE_CDFT_THREADS
            if (n > CDFT_THREADS_BEGIN_N) {
                cftrec4_th(n, a, nw, w);
            } else 
#endif /* USE_CDFT_THREADS */
            if (n > 512) {
                cftrec4(n, a, nw, w);
            } else if (n > 128) {
                cftleaf(n, 1, a, nw, w);
            } else {
                cftfx41(n, a, nw, w);
            }
            bitrv2(n, ip, a);
        } else if (n == 32) {
            cftf161(a, &w[nw - 8]);
            bitrv216(a);
        } else {
            cftf081(a, w);
            bitrv208(a);
        }
    } else if (n == 8) {
        cftf040(a);
    } else if (n == 4) {
        cftx020(a);
    }
}

static void bitrv2conj(int n, int *ip, float *a)
{
    int j, j1, k, k1, l, m, nh, nm;
    float xr, xi, yr, yi;
    
    m = 1;
    for (l = n >> 2; l > 8; l >>= 2) {
        m <<= 1;
    }
    nh = n >> 1;
    nm = 4 * m;
    if (l == 8) {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + 2 * ip[m + k];
                k1 = 4 * k + 2 * ip[m + j];
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + 2 * ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
            j1 += nm;
            k1 += 2 * nm;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 -= nm;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= 2;
            k1 -= nh;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nh + 2;
            k1 += nh + 2;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= nh - nm;
            k1 += 2 * nm - 2;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
        }
    } else {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + ip[m + k];
                k1 = 4 * k + ip[m + j];
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
            j1 += nm;
            k1 += nm;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
        }
    }
}

static void bitrv216neg(float *a)
{
    float x1r, x1i, x2r, x2i, x3r, x3i, x4r, x4i, 
        x5r, x5i, x6r, x6i, x7r, x7i, x8r, x8i, 
        x9r, x9i, x10r, x10i, x11r, x11i, x12r, x12i, 
        x13r, x13i, x14r, x14i, x15r, x15i;
    
    x1r = a[2];
    x1i = a[3];
    x2r = a[4];
    x2i = a[5];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x5r = a[10];
    x5i = a[11];
    x6r = a[12];
    x6i = a[13];
    x7r = a[14];
    x7i = a[15];
    x8r = a[16];
    x8i = a[17];
    x9r = a[18];
    x9i = a[19];
    x10r = a[20];
    x10i = a[21];
    x11r = a[22];
    x11i = a[23];
    x12r = a[24];
    x12i = a[25];
    x13r = a[26];
    x13i = a[27];
    x14r = a[28];
    x14i = a[29];
    x15r = a[30];
    x15i = a[31];
    a[2] = x15r;
    a[3] = x15i;
    a[4] = x7r;
    a[5] = x7i;
    a[6] = x11r;
    a[7] = x11i;
    a[8] = x3r;
    a[9] = x3i;
    a[10] = x13r;
    a[11] = x13i;
    a[12] = x5r;
    a[13] = x5i;
    a[14] = x9r;
    a[15] = x9i;
    a[16] = x1r;
    a[17] = x1i;
    a[18] = x14r;
    a[19] = x14i;
    a[20] = x6r;
    a[21] = x6i;
    a[22] = x10r;
    a[23] = x10i;
    a[24] = x2r;
    a[25] = x2i;
    a[26] = x12r;
    a[27] = x12i;
    a[28] = x4r;
    a[29] = x4i;
    a[30] = x8r;
    a[31] = x8i;
}

static void bitrv208neg(float *a)
{
    float x1r, x1i, x2r, x2i, x3r, x3i, x4r, x4i, 
        x5r, x5i, x6r, x6i, x7r, x7i;
    
    x1r = a[2];
    x1i = a[3];
    x2r = a[4];
    x2i = a[5];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x5r = a[10];
    x5i = a[11];
    x6r = a[12];
    x6i = a[13];
    x7r = a[14];
    x7i = a[15];
    a[2] = x7r;
    a[3] = x7i;
    a[4] = x3r;
    a[5] = x3i;
    a[6] = x5r;
    a[7] = x5i;
    a[8] = x1r;
    a[9] = x1i;
    a[10] = x6r;
    a[11] = x6i;
    a[12] = x2r;
    a[13] = x2i;
    a[14] = x4r;
    a[15] = x4i;
}

static void cftb1st(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, m, mh;
    float wn4r, csc1, csc3, wk1r, wk1i, wk3r, wk3i, 
        wd1r, wd1i, wd3r, wd3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i;
    
    mh = n >> 3;
    m = 2 * mh;
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] + a[j2];
    x0i = -a[1] - a[j2 + 1];
    x1r = a[0] - a[j2];
    x1i = -a[1] + a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[0] = x0r + x2r;
    a[1] = x0i - x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i + x2i;
    a[j2] = x1r + x3i;
    a[j2 + 1] = x1i + x3r;
    a[j3] = x1r - x3i;
    a[j3 + 1] = x1i - x3r;
    wn4r = w[1];
    csc1 = w[2];
    csc3 = w[3];
    wd1r = 1;
    wd1i = 0;
    wd3r = 1;
    wd3i = 0;
    k = 0;
    for (j = 2; j < mh - 2; j += 4) {
        k += 4;
        wk1r = csc1 * (wd1r + w[k]);
        wk1i = csc1 * (wd1i + w[k + 1]);
        wk3r = csc3 * (wd3r + w[k + 2]);
        wk3i = csc3 * (wd3i + w[k + 3]);
        wd1r = w[k];
        wd1i = w[k + 1];
        wd3r = w[k + 2];
        wd3i = w[k + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] + a[j2];
        x0i = -a[j + 1] - a[j2 + 1];
        x1r = a[j] - a[j2];
        x1i = -a[j + 1] + a[j2 + 1];
        y0r = a[j + 2] + a[j2 + 2];
        y0i = -a[j + 3] - a[j2 + 3];
        y1r = a[j + 2] - a[j2 + 2];
        y1i = -a[j + 3] + a[j2 + 3];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 + 2] + a[j3 + 2];
        y2i = a[j1 + 3] + a[j3 + 3];
        y3r = a[j1 + 2] - a[j3 + 2];
        y3i = a[j1 + 3] - a[j3 + 3];
        a[j] = x0r + x2r;
        a[j + 1] = x0i - x2i;
        a[j + 2] = y0r + y2r;
        a[j + 3] = y0i - y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i + x2i;
        a[j1 + 2] = y0r - y2r;
        a[j1 + 3] = y0i + y2i;
        x0r = x1r + x3i;
        x0i = x1i + x3r;
        a[j2] = wk1r * x0r - wk1i * x0i;
        a[j2 + 1] = wk1r * x0i + wk1i * x0r;
        x0r = y1r + y3i;
        x0i = y1i + y3r;
        a[j2 + 2] = wd1r * x0r - wd1i * x0i;
        a[j2 + 3] = wd1r * x0i + wd1i * x0r;
        x0r = x1r - x3i;
        x0i = x1i - x3r;
        a[j3] = wk3r * x0r + wk3i * x0i;
        a[j3 + 1] = wk3r * x0i - wk3i * x0r;
        x0r = y1r - y3i;
        x0i = y1i - y3r;
        a[j3 + 2] = wd3r * x0r + wd3i * x0i;
        a[j3 + 3] = wd3r * x0i - wd3i * x0r;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] + a[j2];
        x0i = -a[j0 + 1] - a[j2 + 1];
        x1r = a[j0] - a[j2];
        x1i = -a[j0 + 1] + a[j2 + 1];
        y0r = a[j0 - 2] + a[j2 - 2];
        y0i = -a[j0 - 1] - a[j2 - 1];
        y1r = a[j0 - 2] - a[j2 - 2];
        y1i = -a[j0 - 1] + a[j2 - 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 - 2] + a[j3 - 2];
        y2i = a[j1 - 1] + a[j3 - 1];
        y3r = a[j1 - 2] - a[j3 - 2];
        y3i = a[j1 - 1] - a[j3 - 1];
        a[j0] = x0r + x2r;
        a[j0 + 1] = x0i - x2i;
        a[j0 - 2] = y0r + y2r;
        a[j0 - 1] = y0i - y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i + x2i;
        a[j1 - 2] = y0r - y2r;
        a[j1 - 1] = y0i + y2i;
        x0r = x1r + x3i;
        x0i = x1i + x3r;
        a[j2] = wk1i * x0r - wk1r * x0i;
        a[j2 + 1] = wk1i * x0i + wk1r * x0r;
        x0r = y1r + y3i;
        x0i = y1i + y3r;
        a[j2 - 2] = wd1i * x0r - wd1r * x0i;
        a[j2 - 1] = wd1i * x0i + wd1r * x0r;
        x0r = x1r - x3i;
        x0i = x1i - x3r;
        a[j3] = wk3i * x0r + wk3r * x0i;
        a[j3 + 1] = wk3i * x0i - wk3r * x0r;
        x0r = y1r - y3i;
        x0i = y1i - y3r;
        a[j3 - 2] = wd3i * x0r + wd3r * x0i;
        a[j3 - 1] = wd3i * x0i - wd3r * x0r;
    }
    wk1r = csc1 * (wd1r + wn4r);
    wk1i = csc1 * (wd1i + wn4r);
    wk3r = csc3 * (wd3r - wn4r);
    wk3i = csc3 * (wd3i - wn4r);
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0 - 2] + a[j2 - 2];
    x0i = -a[j0 - 1] - a[j2 - 1];
    x1r = a[j0 - 2] - a[j2 - 2];
    x1i = -a[j0 - 1] + a[j2 - 1];
    x2r = a[j1 - 2] + a[j3 - 2];
    x2i = a[j1 - 1] + a[j3 - 1];
    x3r = a[j1 - 2] - a[j3 - 2];
    x3i = a[j1 - 1] - a[j3 - 1];
    a[j0 - 2] = x0r + x2r;
    a[j0 - 1] = x0i - x2i;
    a[j1 - 2] = x0r - x2r;
    a[j1 - 1] = x0i + x2i;
    x0r = x1r + x3i;
    x0i = x1i + x3r;
    a[j2 - 2] = wk1r * x0r - wk1i * x0i;
    a[j2 - 1] = wk1r * x0i + wk1i * x0r;
    x0r = x1r - x3i;
    x0i = x1i - x3r;
    a[j3 - 2] = wk3r * x0r + wk3i * x0i;
    a[j3 - 1] = wk3r * x0i - wk3i * x0r;
    x0r = a[j0] + a[j2];
    x0i = -a[j0 + 1] - a[j2 + 1];
    x1r = a[j0] - a[j2];
    x1i = -a[j0 + 1] + a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[j0] = x0r + x2r;
    a[j0 + 1] = x0i - x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i + x2i;
    x0r = x1r + x3i;
    x0i = x1i + x3r;
    a[j2] = wn4r * (x0r - x0i);
    a[j2 + 1] = wn4r * (x0i + x0r);
    x0r = x1r - x3i;
    x0i = x1i - x3r;
    a[j3] = -wn4r * (x0r + x0i);
    a[j3 + 1] = -wn4r * (x0i - x0r);
    x0r = a[j0 + 2] + a[j2 + 2];
    x0i = -a[j0 + 3] - a[j2 + 3];
    x1r = a[j0 + 2] - a[j2 + 2];
    x1i = -a[j0 + 3] + a[j2 + 3];
    x2r = a[j1 + 2] + a[j3 + 2];
    x2i = a[j1 + 3] + a[j3 + 3];
    x3r = a[j1 + 2] - a[j3 + 2];
    x3i = a[j1 + 3] - a[j3 + 3];
    a[j0 + 2] = x0r + x2r;
    a[j0 + 3] = x0i - x2i;
    a[j1 + 2] = x0r - x2r;
    a[j1 + 3] = x0i + x2i;
    x0r = x1r + x3i;
    x0i = x1i + x3r;
    a[j2 + 2] = wk1i * x0r - wk1r * x0i;
    a[j2 + 3] = wk1i * x0i + wk1r * x0r;
    x0r = x1r - x3i;
    x0i = x1i - x3r;
    a[j3 + 2] = wk3i * x0r + wk3r * x0i;
    a[j3 + 3] = wk3i * x0i - wk3r * x0r;
}

static void cftb040(float *a)
{
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i;
    
    x0r = a[0] + a[4];
    x0i = a[1] + a[5];
    x1r = a[0] - a[4];
    x1i = a[1] - a[5];
    x2r = a[2] + a[6];
    x2i = a[3] + a[7];
    x3r = a[2] - a[6];
    x3i = a[3] - a[7];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[2] = x1r + x3i;
    a[3] = x1i - x3r;
    a[4] = x0r - x2r;
    a[5] = x0i - x2i;
    a[6] = x1r - x3i;
    a[7] = x1i + x3r;
}

static void cftbsub(int n, float *a, int *ip, int nw, float *w)
{
    void bitrv2conj(int n, int *ip, float *a);
    void bitrv216neg(float *a);
    void bitrv208neg(float *a);
    void cftb1st(int n, float *a, float *w);
    void cftrec4(int n, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftfx41(int n, float *a, int nw, float *w);
    void cftf161(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftb040(float *a);
    void cftx020(float *a);
#ifdef USE_CDFT_THREADS
    void cftrec4_th(int n, float *a, int nw, float *w);
#endif /* USE_CDFT_THREADS */
    
    if (n > 8) {
        if (n > 32) {
            cftb1st(n, a, &w[nw - (n >> 2)]);
#ifdef USE_CDFT_THREADS
            if (n > CDFT_THREADS_BEGIN_N) {
                cftrec4_th(n, a, nw, w);
            } else 
#endif /* USE_CDFT_THREADS */
            if (n > 512) {
                cftrec4(n, a, nw, w);
            } else if (n > 128) {
                cftleaf(n, 1, a, nw, w);
            } else {
                cftfx41(n, a, nw, w);
            }
            bitrv2conj(n, ip, a);
        } else if (n == 32) {
            cftf161(a, &w[nw - 8]);
            bitrv216neg(a);
        } else {
            cftf081(a, w);
            bitrv208neg(a);
        }
    } else if (n == 8) {
        cftb040(a);
    } else if (n == 4) {
        cftx020(a);
    }
}

static void rftfsub(int n, float *a, int nc, float *c)
{
    int j, k, kk, ks, m;
    float wkr, wki, xr, xi, yr, yi;
    
    m = n >> 1;
    ks = 2 * nc / m;
    kk = 0;
    for (j = 2; j < m; j += 2) {
        k = n - j;
        kk += ks;
        wkr = 0.5 - c[nc - kk];
        wki = c[kk];
        xr = a[j] - a[k];
        xi = a[j + 1] + a[k + 1];
        yr = wkr * xr - wki * xi;
        yi = wkr * xi + wki * xr;
        a[j] -= yr;
        a[j + 1] -= yi;
        a[k] += yr;
        a[k + 1] -= yi;
    }
}

static void rftbsub(int n, float *a, int nc, float *c)
{
    int j, k, kk, ks, m;
    float wkr, wki, xr, xi, yr, yi;
    
    m = n >> 1;
    ks = 2 * nc / m;
    kk = 0;
    for (j = 2; j < m; j += 2) {
        k = n - j;
        kk += ks;
        wkr = 0.5 - c[nc - kk];
        wki = c[kk];
        xr = a[j] - a[k];
        xi = a[j + 1] + a[k + 1];
        yr = wkr * xr + wki * xi;
        yi = wkr * xi - wki * xr;
        a[j] -= yr;
        a[j + 1] -= yi;
        a[k] += yr;
        a[k + 1] -= yi;
    }
}

static void rdft(int n, int isgn, float *a, int *ip, float *w)
{
    void makewt(int nw, int *ip, float *w);
    void makect(int nc, int *ip, float *c);
    void cftfsub(int n, float *a, int *ip, int nw, float *w);
    void cftbsub(int n, float *a, int *ip, int nw, float *w);
    void rftfsub(int n, float *a, int nc, float *c);
    void rftbsub(int n, float *a, int nc, float *c);
    int nw, nc;
    float xi;
    
    nw = ip[0];
    if (n > (nw << 2)) {
        nw = n >> 2;
        makewt(nw, ip, w);
    }
    nc = ip[1];
    if (n > (nc << 2)) {
        nc = n >> 2;
        makect(nc, ip, w + nw);
    }
    if (isgn >= 0) {
        if (n > 4) {
            cftfsub(n, a, ip, nw, w);
            rftfsub(n, a, nc, w + nw);
        } else if (n == 4) {
            cftfsub(n, a, ip, nw, w);
        }
        xi = a[0] - a[1];
        a[0] += a[1];
        a[1] = xi;
    } else {
        a[1] = 0.5 * (a[0] - a[1]);
        a[0] -= a[1];
        if (n > 4) {
            rftbsub(n, a, nc, w + nw);
            cftbsub(n, a, ip, nw, w);
        } else if (n == 4) {
            cftbsub(n, a, ip, nw, w);
        }
    }
}

// input array (any shape >= 1D)
// output array (shape = input.shape.replace(axis, n).insert(0,2))
// d0 = input.shape.step(axis)
// d1 = input.shape.size(axis)
// d2 = input.shape.slot(axis)
static inline void rfft_libfft_f32(
    const float* restrict input, 
    float* restrict output, 
    int d0, int d1, int d2,
    int32_t* restrict temp_ip, float* restrict temp_w, float* restrict temp_a)
{
    void rdft(int n, int isgn, float* a, int* ip, float* w);

    int d3 = d0 * d1;
    int d_out = (d1 >> 1) + 1;

    for (int k = 0; k < d2; k++)
    {
        int dk = k * d3;
        int dm = k * 2 * d_out * d0;
        for (int i = 0; i < d0; i++)
        {                	           
            for (int j = 0; j < d1; j++)
            {
                temp_a[j] = input[dk + j * d0 + i];
            }
            rdft(d1, 1, temp_a, (int *)temp_ip, temp_w);

            for (int m = 2; m < d1; m+=2)
            {
                int index = (m * d0) + 2 * i + dm;
                output[index] = temp_a[m];
                output[index + 1] = -temp_a[m + 1];
            }
            int beta = dm + 2 * i;
            output[beta] = temp_a[0];
            output[beta + 1] = 0;
            output[beta + d3] = temp_a[1];
            output[beta + d3 + 1] = 0;
        }
    }
}

static inline int mtb_model_raw(const void* handle,
	const void* restrict src, int src_count,
	void* restrict dst, int dst_byte_count)
{
	mtb_ml_model_t* model = *(mtb_ml_model_t**)handle;
	mtb_ml_model_run(model, (MTB_ML_DATA_T*)src);
	
	int ret_status = model->lib_error;
	if (ret_status != 0) {printf("ERROR: TensorFlow Lite model inference failed with error code: %d.\r\n", ret_status);}
	CY_ASSERT(ret_status == 0);

	memcpy(dst, model->output, dst_byte_count);

	return IPWIN_RET_SUCCESS;
}

/**
 * Enqueue handle->input_size values from given *data pointer to internal window buffer.
 *
 * @param handle Pointer to an initialized handle.
 * @param data Data to enqueue.
 * @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_ERROR (-2) if internal buffer is out of memory.
 */
static inline int fixwin_enqueue(void* restrict handle, const void* restrict data)
{
	fixwin_t* fep = (fixwin_t*)handle;

	if (cbuffer_enqueue(&fep->data_buffer, data, fep->input_size) != 0)
		return IPWIN_RET_ERROR;

	return IPWIN_RET_SUCCESS;
}

static inline void mtb_model_free(const void* handle)
{
	mtb_ml_model_t* model = *(mtb_ml_model_t**)handle;
	mtb_ml_model_deinit(model);

#ifndef IMAI_NO_NPU
	mtb_ml_deinit();
#endif

	if (IMAI_mtb_models_count > 0)
		IMAI_mtb_models_count--;
}

/**
* Initializes a fixwin sampler handle.
*
* @param handle Pointer to a preallocated memory area of fixwin_handle_size() bytes to initialize.
*
* @param input_size Number of bytes to enqueue.
* @param count Number of items (of size input_size) in each window
*/
static inline void fixwin_init(void* restrict handle, int input_size, int count)
{
	fixwin_t* fep = (fixwin_t*)handle;
	fep->input_size = input_size;

	char* mem = ((char*)handle) + sizeof(fixwin_t);

	int data_buffer = input_size * count;
	
	cbuffer_init(&fep->data_buffer, mem, data_buffer);
}

static inline int mtb_model_soft_reset(const void* handle)
{
	mtb_ml_model_t* model = *(mtb_ml_model_t**)handle;

	cy_rslt_t result = mtb_ml_model_rnn_reset_all_parameters(model);

	if (result != MTB_ML_RESULT_SUCCESS)
		return IPWIN_RET_ERROR;

	return IPWIN_RET_SUCCESS;
}

#if defined(IMAI_PROFILING_LOG)
#define MODEL_PROFILING MTB_ML_LOG_ENABLE_MODEL_LOG
#elif defined(IMAI_PROFILING)
#define MODEL_PROFILING MTB_ML_PROFILE_ENABLE_MODEL
#endif

#define IMAI_MAX_MTB_MODELS 4
uint8_t IMAI_mtb_models_count = 0;
mtb_ml_model_t* IMAI_mtb_models[IMAI_MAX_MTB_MODELS];

void IMAI_mtb_models_print_info() {
	if (IMAI_mtb_models_count < 1)
		return;

	printf("Loaded %ld models:\r\n", (long int)IMAI_mtb_models_count);
	for (uint32_t index = 0; index < IMAI_mtb_models_count; index++) {
		printf("Model %ld:\r\n", (long int)index);
		mtb_ml_utils_print_model_info(IMAI_mtb_models[index]);
		printf("\r\n");
	}
	printf("\r\n");
}

void IMAI_mtb_models_profile_log() {
	if (IMAI_mtb_models_count < 1)
		return;

	printf("Profiling %ld models:\r\n", (long int)IMAI_mtb_models_count);
	for (uint32_t index = 0; index < IMAI_mtb_models_count; index++) {
		printf("Model %ld: %s:\r\n", (long int)index, IMAI_mtb_models[index]->name);
		mtb_ml_model_profile_log(IMAI_mtb_models[index]);
		printf("\r\n");
	}
	printf("\r\n");
}

static int mtb_init(const void* handle, uint8_t* model_bin, unsigned int model_size, uint8_t* arena_buffer, int arena_size, int npu_priority, char model_name[]) {
	mtb_ml_model_t** model_obj = (mtb_ml_model_t**)handle;

	mtb_ml_model_bin_t model = {
		.model_bin = model_bin,
		.model_size = model_size,
		.arena_size = arena_size
	};

	strncpy(model.name, model_name, MTB_ML_MODEL_NAME_LEN - 1);
	model.name[MTB_ML_MODEL_NAME_LEN - 1] = '\0';

	mtb_ml_model_buffer_t buffer = {
		.tensor_arena = arena_buffer,
		.tensor_arena_size = arena_size
	};

	if (mtb_ml_model_init(&model, &buffer, model_obj) != CY_RSLT_SUCCESS)
		return IPWIN_RET_ERROR;

#ifndef IMAI_NO_NPU
	if (mtb_ml_init(npu_priority) != CY_RSLT_SUCCESS)
		return IPWIN_RET_ERROR;
#endif

#if defined(IMAI_PROFILING) || defined(IMAI_PROFILING_LOG)
	if (mtb_ml_model_profile_config(*model_obj, MODEL_PROFILING) != CY_RSLT_SUCCESS)
		return IPWIN_RET_ERROR;

	IMAI_mtb_models[IMAI_mtb_models_count++] = *model_obj;
#endif

	return IPWIN_RET_SUCCESS;
}

#ifndef __CLOSE_HOOKS
	#define __CLOSE_HOOKS() do { } while(0)
#endif
#define __RETURN_ERROR(_exp) do { int __ret = (_exp); if(__ret < 0) { __CLOSE_HOOKS(); return __ret; } } while(0)
#define __RETURN_ALWAYS(_exp) __CLOSE_HOOKS(); return (_exp)
#define __RETURN_ERROR_BREAK_EMPTY(_exp) {  int __ret = (_exp); if(__ret == -1) break; if(__ret < 0) { __CLOSE_HOOKS(); return __ret; } }
#define __RETURN_ERROR_BREAK_EMPTY_END(_exp) {  int __ret = (_exp); if(__ret == -1 || __ret == -3) break; if(__ret < 0) { __CLOSE_HOOKS(); return __ret; } }
#define __RETURN_ERROR_CANCEL_EMPTY(_exp) {  int __ret = (_exp); if(__ret == -1) { __CLOSE_HOOKS(); return 0; } if(__ret < 0) { __CLOSE_HOOKS(); return __ret; } }
#define __BREAK_ERROR(_exp) {  int __ret = (_exp); if(__ret < 0) break; }
#define __CONTINUE_ON_EMPTY(_exp) {  int __ret = (_exp); if(__ret < -1) { __CLOSE_HOOKS(); return __ret; } }

/*
* Try read data from model.
* 
*  @param data_out Output features. Output float[4].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*/
int IMAI_dequeue(float *restrict data_out) {    
    __HOOK_REGION(true, 0);
    __RETURN_ERROR(fixwin_dequeue(_K2, _K1, 8000, 1000));
    rfft_libfft_f32(_K1, _K3, 1, 2, 8000, _K10, _K11, _K12);
    __HOOK_REGION(false, 0);
    __HOOK_REGION(true, 1);
    __RETURN_ERROR(mtb_model_raw(_K8, _K3, 32000, data_out, 16));
    __HOOK_REGION(false, 1);
    return 0;
}

/*
* Try write data to model.
* 
*  @param data_in Input features. Input float[2].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*/
int IMAI_enqueue(const float *restrict data_in) {    
    __HOOK_REGION(true, 0);
    __RETURN_ERROR(fixwin_enqueue(_K2, data_in));
    __HOOK_REGION(false, 0);
    return 0;
}

/*
* Closes and flushes streams, free any heap allocated memory.
* 
*/
void IMAI_finalize(void) {    
    mtb_model_free(_K8);
}

/*
* Resets windows and neural networks(i.e. RNNs) to initial state.
* 
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*/
int IMAI_soft_reset(void) {    
    fixwin_init(_K2, 8, 8000);
    __RETURN_ERROR(mtb_model_soft_reset(_K8));
    return 0;
}

/*
* Initializes buffers to initial state.
* 
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*/
int IMAI_init(void) {    
    fixwin_init(_K2, 8, 8000);
    __RETURN_ERROR(mtb_init(_K8, _K5, 31744, _K4, 1110016, 3, "network_float"));
    return 0;
}

static IMAI_api_def _IMAI_api_def = {
    .api_ver = 1,
    .id = {0xbe, 0x66, 0x27, 0x64, 0xb0, 0xf0, 0x4f, 0x44, 0xaa, 0x08, 0xb0, 0xea, 0xbc, 0x63, 0x6a, 0x73},
    .api_type = IMAI_API_TYPE_QUEUE,
    .prefix = "IMAI_",
    .buffer_mem = {
        .size = 192024,
        .peak_usage = 192024,
    },
    .static_mem = {
        .size = 1174264,
        .peak_usage = 1174256,
    },
    .readonly_mem = {
        .size = 31744,
        .peak_usage = 31744,
    },
    .func_count = 5,
    .func_list = (IMAI_func_def[]) {
        {
            .name = "IMAI_dequeue",
            .description = "Try read data from model.",
            .fn_ptr = IMAI_dequeue,
            .attrib = 3,
            .param_count = 1,
            .param_list = (IMAI_param_def[]) {
                {
                    .name = "data_out",
                    .attrib = IMAI_PARAM_OUTPUT,
                    .rank = 1,
                    .shape = (IMAI_shape_dim[]) {
                        {
                            .name = "Labels",
                            .size = 4,
                            .labels = (label_text_t[]) { "unlabeled","east","north","west" },
                        },
                    },
                    .count = 4,
                    .bytes = 16,
                    .type_id = IMAGINET_TYPES_FLOAT32,
                    .frequency = 16,
                    .shift = 0,
                    .scale = 0,
                    .offset = 0,
                },
            },
        },
        {
            .name = "IMAI_enqueue",
            .description = "Try write data to model.",
            .fn_ptr = IMAI_enqueue,
            .attrib = 3,
            .param_count = 1,
            .param_list = (IMAI_param_def[]) {
                {
                    .name = "data_in",
                    .attrib = IMAI_PARAM_INPUT,
                    .rank = 1,
                    .shape = (IMAI_shape_dim[]) {
                        {
                            .name = "",
                            .size = 2,
                        },
                    },
                    .count = 2,
                    .bytes = 8,
                    .type_id = IMAGINET_TYPES_FLOAT32,
                    .frequency = 16000,
                    .shift = 0,
                    .scale = 1,
                    .offset = 0,
                },
            },
        },
        {
            .name = "IMAI_finalize",
            .description = "Closes and flushes streams, free any heap allocated memory.",
            .fn_ptr = IMAI_finalize,
            .attrib = 10,
            .param_count = 0,
            .param_list = (IMAI_param_def[]) {
            },
        },
        {
            .name = "IMAI_soft_reset",
            .description = "Resets windows and neural networks(i.e. RNNs) to initial state.",
            .fn_ptr = IMAI_soft_reset,
            .attrib = 67,
            .param_count = 0,
            .param_list = (IMAI_param_def[]) {
            },
        },
        {
            .name = "IMAI_init",
            .description = "Initializes buffers to initial state.",
            .fn_ptr = IMAI_init,
            .attrib = 7,
            .param_count = 0,
            .param_list = (IMAI_param_def[]) {
            },
        },
    },
};

IMAI_api_def *IMAI_api(void) {
    return &_IMAI_api_def;
}

