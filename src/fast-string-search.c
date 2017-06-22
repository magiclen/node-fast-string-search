#include <node_api.h>

#include <stdlib.h>

napi_value createEmptyArray(napi_env env){
        napi_value result;
        napi_create_array_with_length(env, 0, &result);
        return result;
}

napi_value boyerMooreMagicLen(napi_env env, char16_t* source, int64_t sourceLength, char16_t* pattern, int64_t patternLength, int64_t offset, int64_t limit){
        if (patternLength == 0 || offset < 0 || sourceLength - offset < patternLength) {
                return createEmptyArray(env);
        }
        if(limit <= 0) {
                limit = 1000;
        }

        uint32_t* buffer;
        napi_value arrayBuffer;
        napi_create_arraybuffer(env, limit * 4, (void**)(&buffer), &arrayBuffer);

        int64_t sourceLength_dec = sourceLength - 1;
        int64_t patternLength_dec = patternLength - 1;
        napi_value resultList;
        uint32_t resultListLength = 0;
        int64_t badCharShiftMap[65536] = { patternLength };
        int64_t i;
        for (i = 0; i < patternLength_dec; ++i) {
                char16_t index = pattern[i];
                badCharShiftMap[index] = patternLength_dec - i;
        }
        char16_t specialChar = pattern[patternLength_dec];
        int64_t specialShift = badCharShiftMap[specialChar];
        badCharShiftMap[specialChar] = 0;
        int64_t sourcePointer = offset + patternLength_dec;
        int64_t patternPointer;
        while (sourcePointer < sourceLength) {
                patternPointer = patternLength_dec;
                while (patternPointer >= 0) {
                        if (source[sourcePointer] != pattern[patternPointer]) {
                                break;
                        }
                        --sourcePointer;
                        --patternPointer;
                }
                int64_t starePointer = sourcePointer;
                int64_t goodSuffixLength_inc = patternLength - patternPointer;
                sourcePointer += goodSuffixLength_inc;
                if (patternPointer < 0) {
                        buffer[resultListLength++] = starePointer + 1;
                        if (sourcePointer > sourceLength_dec || resultListLength == limit) {
                                break;
                        } else {
                                sourcePointer += badCharShiftMap[source[sourcePointer]];
                                continue;
                        }
                }
                int64_t shift1 = (sourcePointer <= sourceLength_dec) ? badCharShiftMap[source[sourcePointer]] : 0;
                if (shift1 >= patternLength_dec) {
                        sourcePointer += shift1;
                } else {
                        int64_t shift2 = ((source[starePointer] == specialChar) ? specialShift : badCharShiftMap[source[starePointer]]) - goodSuffixLength_inc;
                        sourcePointer += (shift1 >= shift2) ? shift1 : shift2;
                }
        }
        napi_create_typedarray(env, napi_uint32_array, resultListLength, arrayBuffer, 0, &resultList);
        return resultList;
}

napi_value boyerMooreMagicLenSkip(napi_env env, char16_t* source, int64_t sourceLength, char16_t* pattern, int64_t patternLength, int64_t offset, int64_t limit){
        if (patternLength == 0 || offset < 0 || sourceLength - offset < patternLength) {
                return createEmptyArray(env);
        }
        if(limit <= 0) {
                limit = 1000;
        }

        uint32_t* buffer;
        napi_value arrayBuffer;
        napi_create_arraybuffer(env, limit * 4, (void**)(&buffer), &arrayBuffer);

        int64_t sourceLength_dec = sourceLength - 1;
        int64_t patternLength_dec = patternLength - 1;
        napi_value resultList;
        uint32_t resultListLength = 0;
        int64_t badCharShiftMap[65536] = { patternLength };
        int64_t i;
        for (i = 0; i < patternLength_dec; ++i) {
                char16_t index = pattern[i];
                badCharShiftMap[index] = patternLength_dec - i;
        }
        char16_t specialChar = pattern[patternLength_dec];
        int64_t specialShift = badCharShiftMap[specialChar];
        badCharShiftMap[specialChar] = 0;
        int64_t sourcePointer = offset + patternLength_dec;
        int64_t patternPointer;
        while (sourcePointer < sourceLength) {
                patternPointer = patternLength_dec;
                while (patternPointer >= 0) {
                        if (source[sourcePointer] != pattern[patternPointer]) {
                                break;
                        }
                        --sourcePointer;
                        --patternPointer;
                }
                int64_t starePointer = sourcePointer;
                int64_t goodSuffixLength_inc = patternLength - patternPointer;
                sourcePointer += goodSuffixLength_inc;
                if (patternPointer < 0) {
                        buffer[resultListLength++] = starePointer + 1;
                        if (sourcePointer > sourceLength_dec || resultListLength == limit) {
                                break;
                        } else {
                                sourcePointer += patternLength_dec;
                                continue;
                        }
                }
                int64_t shift1 = (sourcePointer <= sourceLength_dec) ? badCharShiftMap[source[sourcePointer]] : 0;
                if (shift1 >= patternLength_dec) {
                        sourcePointer += shift1;
                } else {
                        int64_t shift2 = ((source[starePointer] == specialChar) ? specialShift : badCharShiftMap[source[starePointer]]) - goodSuffixLength_inc;
                        sourcePointer += (shift1 >= shift2) ? shift1 : shift2;
                }
        }
        napi_create_typedarray(env, napi_uint32_array, resultListLength, arrayBuffer, 0, &resultList);
        return resultList;
}

napi_value boyerMooreMagicLenRev(napi_env env, char16_t* source, int64_t sourceLength, char16_t* pattern, int64_t patternLength, int64_t offset, int64_t limit){
        if (patternLength == 0 || offset < 0 || sourceLength - offset < patternLength) {
                return createEmptyArray(env);
        }
        if(limit <= 0) {
                limit = 1000;
        }

        uint32_t* buffer;
        napi_value arrayBuffer;
        napi_create_arraybuffer(env, limit * 4, (void**)(&buffer), &arrayBuffer);

        int64_t sourceLength_dec = sourceLength - 1;
        int64_t patternLength_dec = patternLength - 1;
        napi_value resultList;
        napi_create_array(env, &resultList);
        int64_t resultListLength = 0;
        int64_t badCharShiftMap[65536] = { patternLength };
        int64_t i;
        for (i = patternLength_dec; i > 0; --i) {
                char16_t index = pattern[i];
                badCharShiftMap[index] = i;
        }
        char16_t specialChar = pattern[patternLength_dec];
        int64_t specialShift = badCharShiftMap[specialChar];
        badCharShiftMap[specialChar] = 0;
        int64_t sourcePointer = sourceLength_dec - patternLength_dec;
        int64_t patternPointer;
        while (sourcePointer >= offset) {
                patternPointer = 0;
                while (patternPointer < patternLength) {
                        if (source[sourcePointer] != pattern[patternPointer]) {
                                break;
                        }
                        ++sourcePointer;
                        ++patternPointer;
                }
                int64_t starePointer = sourcePointer;
                int64_t goodSuffixLength_inc = patternPointer + 1;
                sourcePointer -= goodSuffixLength_inc;
                if (patternPointer >= patternLength) {
                        buffer[resultListLength++] = sourcePointer + 1;
                        if (sourcePointer < 0 || resultListLength == limit) {
                                break;
                        } else {
                                sourcePointer -= badCharShiftMap[source[sourcePointer]];
                                continue;
                        }
                }
                int64_t shift1 = (sourcePointer >= 0) ? badCharShiftMap[source[sourcePointer]] : 0;
                if (shift1 >= patternLength_dec) {
                        sourcePointer -= shift1;
                } else {
                        int64_t shift2 = ((source[starePointer] == specialChar) ? specialShift : badCharShiftMap[source[starePointer]]) - goodSuffixLength_inc;
                        sourcePointer -= (shift1 >= shift2) ? shift1 : shift2;
                }
        }
        napi_create_typedarray(env, napi_uint32_array, resultListLength, arrayBuffer, 0, &resultList);
        return resultList;
}

napi_value indexOf(napi_env env, napi_callback_info info){
        size_t argsLength = 4;
        napi_value args[4];
        napi_get_cb_info(env, info, &argsLength, args, 0, 0);

        if(argsLength < 2) {
                return createEmptyArray(env);
        }
        size_t sourceLength, patternLength;
        napi_get_value_string_utf16(env, args[0], NULL, 0, &sourceLength);
        napi_get_value_string_utf16(env, args[1], NULL, 0, &patternLength);

        char16_t* source = (char16_t*)malloc(sizeof(char16_t) * (sourceLength + 1));
        char16_t* pattern = (char16_t*)malloc(sizeof(char16_t) * (patternLength + 1));
        napi_get_value_string_utf16(env, args[0], source, sourceLength  + 1, &sourceLength);
        napi_get_value_string_utf16(env, args[1], pattern, patternLength + 1, &patternLength);

        int64_t offset = 0;
        int64_t limit = 0;
        if(argsLength >= 4) {
                napi_get_value_int64(env, args[2], &offset);
                napi_get_value_int64(env, args[3], &limit);
        }else if(argsLength == 3) {
                napi_get_value_int64(env, args[2], &offset);
        }
        napi_value result = boyerMooreMagicLen(env, source, sourceLength, pattern, patternLength, offset, limit);
        free(source);
        free(pattern);
        return result;
}

napi_value indexOfSkip(napi_env env, napi_callback_info info){
        size_t argsLength = 4;
        napi_value args[4];
        napi_get_cb_info(env, info, &argsLength, args, 0, 0);

        if(argsLength < 2) {
                return createEmptyArray(env);
        }
        size_t sourceLength, patternLength;
        napi_get_value_string_utf16(env, args[0], NULL, 0, &sourceLength);
        napi_get_value_string_utf16(env, args[1], NULL, 0, &patternLength);

        char16_t* source = (char16_t*)malloc(sizeof(char16_t) * (sourceLength + 1));
        char16_t* pattern = (char16_t*)malloc(sizeof(char16_t) * (patternLength + 1));
        napi_get_value_string_utf16(env, args[0], source, sourceLength  + 1, &sourceLength);
        napi_get_value_string_utf16(env, args[1], pattern, patternLength + 1, &patternLength);

        int64_t offset = 0;
        int64_t limit = 0;
        if(argsLength >= 4) {
                napi_get_value_int64(env, args[2], &offset);
                napi_get_value_int64(env, args[3], &limit);
        }else if(argsLength == 3) {
                napi_get_value_int64(env, args[2], &offset);
        }
        napi_value result = boyerMooreMagicLenSkip(env, source, sourceLength, pattern, patternLength, offset, limit);
        free(source);
        free(pattern);
        return result;
}

napi_value lastIndexOf(napi_env env, napi_callback_info info){
        size_t argsLength = 4;
        napi_value args[4];
        napi_get_cb_info(env, info, &argsLength, args, 0, 0);

        if(argsLength < 2) {
                return createEmptyArray(env);
        }
        size_t sourceLength, patternLength;
        napi_get_value_string_utf16(env, args[0], NULL, 0, &sourceLength);
        napi_get_value_string_utf16(env, args[1], NULL, 0, &patternLength);

        char16_t* source = (char16_t*)malloc(sizeof(char16_t) * (sourceLength + 1));
        char16_t* pattern = (char16_t*)malloc(sizeof(char16_t) * (patternLength + 1));
        napi_get_value_string_utf16(env, args[0], source, sourceLength  + 1, &sourceLength);
        napi_get_value_string_utf16(env, args[1], pattern, patternLength + 1, &patternLength);

        int64_t offset = 0;
        int64_t limit = 0;
        if(argsLength >= 4) {
                napi_get_value_int64(env, args[2], &offset);
                napi_get_value_int64(env, args[3], &limit);
        }else if(argsLength == 3) {
                napi_get_value_int64(env, args[2], &offset);
        }
        napi_value result = boyerMooreMagicLenRev(env, source, sourceLength, pattern, patternLength, offset, limit);
        free(source);
        free(pattern);
        return result;
}

napi_value utf16IndexOf(napi_env env, napi_callback_info info){
        size_t argsLength = 4;
        napi_value args[4];
        napi_get_cb_info(env, info, &argsLength, args, 0, 0);
        if(argsLength < 2) {
                return createEmptyArray(env);
        }

        char* sourceDataChars;
        size_t sourceDataLength;
        napi_get_buffer_info(env, args[0], (void**)(&sourceDataChars), &sourceDataLength);

        size_t sourceDataChars16Length = sourceDataLength / 2;
        char16_t* sourceDataChars16 = (char16_t*)sourceDataChars;

        char* patternDataChars;
        size_t patternDataLength;
        napi_get_buffer_info(env, args[1], (void**)(&patternDataChars), &patternDataLength);

        size_t patternDataChars16Length = patternDataLength / 2;
        char16_t* patternDataChars16 = (char16_t*)patternDataChars;

        int64_t offset = 0;
        int64_t limit = 0;
        if(argsLength >= 4) {
                napi_get_value_int64(env, args[2], &offset);
                napi_get_value_int64(env, args[3], &limit);
        }else if(argsLength == 3) {
                napi_get_value_int64(env, args[2], &offset);
        }
        napi_value result = boyerMooreMagicLen(env, sourceDataChars16, sourceDataChars16Length, patternDataChars16, patternDataChars16Length, offset, limit);
        return result;
}

napi_value utf16IndexOfSkip(napi_env env, napi_callback_info info){
        size_t argsLength = 4;
        napi_value args[4];
        napi_get_cb_info(env, info, &argsLength, args, 0, 0);
        if(argsLength < 2) {
                return createEmptyArray(env);
        }

        char* sourceDataChars;
        size_t sourceDataLength;
        napi_get_buffer_info(env, args[0], (void**)(&sourceDataChars), &sourceDataLength);

        size_t sourceDataChars16Length = sourceDataLength / 2;
        char16_t* sourceDataChars16 = (char16_t*)sourceDataChars;

        char* patternDataChars;
        size_t patternDataLength;
        napi_get_buffer_info(env, args[1], (void**)(&patternDataChars), &patternDataLength);

        size_t patternDataChars16Length = patternDataLength / 2;
        char16_t* patternDataChars16 = (char16_t*)patternDataChars;

        int64_t offset = 0;
        int64_t limit = 0;
        if(argsLength >= 4) {
                napi_get_value_int64(env, args[2], &offset);
                napi_get_value_int64(env, args[3], &limit);
        }else if(argsLength == 3) {
                napi_get_value_int64(env, args[2], &offset);
        }
        napi_value result = boyerMooreMagicLenSkip(env, sourceDataChars16, sourceDataChars16Length, patternDataChars16, patternDataChars16Length, offset, limit);
        return result;
}

napi_value utf16LastIndexOf(napi_env env, napi_callback_info info){
        size_t argsLength = 4;
        napi_value args[4];
        napi_get_cb_info(env, info, &argsLength, args, 0, 0);

        if(argsLength < 2) {
                return createEmptyArray(env);
        }

        char* sourceDataChars;
        size_t sourceDataLength;
        napi_get_buffer_info(env, args[0], (void**)(&sourceDataChars), &sourceDataLength);

        size_t sourceDataChars16Length = sourceDataLength / 2;
        char16_t* sourceDataChars16 = (char16_t*)sourceDataChars;

        char* patternDataChars;
        size_t patternDataLength;
        napi_get_buffer_info(env, args[1], (void**)(&patternDataChars), &patternDataLength);

        size_t patternDataChars16Length = patternDataLength / 2;
        char16_t* patternDataChars16 = (char16_t*)patternDataChars;

        int64_t offset = 0;
        int64_t limit = 0;
        if(argsLength >= 4) {
                napi_get_value_int64(env, args[2], &offset);
                napi_get_value_int64(env, args[3], &limit);
        }else if(argsLength == 3) {
                napi_get_value_int64(env, args[2], &offset);
        }
        napi_value result = boyerMooreMagicLenRev(env, sourceDataChars16, sourceDataChars16Length, patternDataChars16, patternDataChars16Length, offset, limit);
        return result;
}

void Init (napi_env env, napi_value exports, napi_value module, void* priv) {
        napi_property_descriptor allDesc[] = {
                {"indexOf", 0, indexOf, 0, 0, 0, napi_default, 0},
                {"indexOfSkip", 0, indexOfSkip, 0, 0, 0, napi_default, 0},
                {"utf16IndexOf", 0, utf16IndexOf, 0, 0, 0, napi_default, 0},
                {"utf16IndexOfSkip", 0, utf16IndexOfSkip, 0, 0, 0, napi_default, 0},
                {"lastIndexOf", 0, lastIndexOf, 0, 0, 0, napi_default, 0},
                {"utf16LastIndexOf", 0, utf16LastIndexOf, 0, 0, 0, napi_default, 0}
        };
        napi_define_properties(env, exports, 6, allDesc);
}

NAPI_MODULE(fss, Init);
