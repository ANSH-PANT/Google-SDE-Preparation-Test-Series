/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

struct letters {
    char c;
    int freq;
};

int cmp(const void* a, const void* b) {
    struct letters* v1 = (struct letters*)a;
    struct letters* v2 = (struct letters*)b;
    return v2->freq - v1->freq;
}

char* reorganizeString(char* s) {
    char* res;
    int k;
    struct letters v[26] = {0};
    int i;
    int len = strlen(s);
    int idx;
    int j;
    res = (char*)malloc(len + 1);
    memset(res, '\0', len + 1);
    for (i = 0; i < len; i++) {
        idx = s[i] - 97;
        v[idx].c = s[i];
        v[idx].freq++;
    }
    qsort(v, 26, sizeof(struct letters), cmp);
    if (v[0].freq > (len + 1) / 2) {
        return "";
    }
    int resIdx = 0;
    for (i = 0; i < 26; i++) {
        if (v[i].freq == 0)
            continue;
        while (v[i].freq--) {
            res[resIdx] = v[i].c;
            resIdx += 2;
            if (resIdx >= len)
                resIdx = 1;
        }
    }
    res[len] = NULL;
    return &res[0];
}
