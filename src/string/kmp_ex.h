








/* 扩展KMP：给出模板串A和子串B，长度分别为lenA和lenB，要求在线性时间内，对于每个A[i]（0<=i<lenA)，求出A[i..lenA-1]与B的最长公共前缀长度，记为ex[i]（或者说，ex[i]为满足A[i..i+z-1]==B[0..z-1]的最大的z值）。扩展KMP可以用来解决很多字符串问题，如求一个字符串的最长回文子串和最长重复子串。 
*/
	lenA = strlen(A); lenB = strlen(B);
    next[0] = lenB; next[1] = lenB - 1;
    re(i, lenB-1) if (B[i] != B[i + 1]) {next[1] = i; break;}
    int j, k = 1, p, L;
    re2(i, 2, lenB) {
        p = k + next[k] - 1; L = next[i - k];
        if (i + L <= p) next[i] = L; else {
            j = p - i + 1;
            if (j < 0) j = 0;
            while (i + j < lenB && B[i + j] == B[j]) j++;
            next[i] = j; k = i;
        }
    }
    int minlen = lenA <= lenB ? lenA : lenB; ex[0] = minlen;
    re(i, minlen) if (A[i] != B[i]) {ex[0] = i; break;}
    k = 0;
    re2(i, 1, lenA) {
        p = k + ex[k] - 1; L = next[i - k];
        if (i + L <= p) ex[i] = L; else {
            j = p - i + 1;
            if (j < 0) j = 0;
            while (i + j < lenA && j < lenB && A[i + j] == B[j]) j++;
            ex[i] = j; k = i;
        }
    }
