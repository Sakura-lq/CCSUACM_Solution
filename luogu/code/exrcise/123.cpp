#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param operators string字符串vector<vector<>> the ops
     * @return string字符串vector
     */

    struct trieNode
    {
        int pass;
        int end;
        trieNode *next[26];

        trieNode() : pass(0), end(0)
        {
            for (int i = 0; i < 26; ++i)
            {
                next[i] = nullptr;
            }
        }
    };

    trieNode root;

    void insert(string word)
    {
        int sz = word.length();
        trieNode *p = &root;

        for (int i = 0; i < sz; i++)
        {
            int c = word[i] - 'a';
            if (p->next[c] == nullptr)
            {
                p->next[c] = new trieNode();
            }
            p->pass++;
            p = p->next[c];
        }

        p->end++;
    }

    void deletes(string word)
    {
        int sz = word.length();
        trieNode *p = &root;

        for (int i = 0; i < sz; i++)
        {
            int c = word[i] - 'a';
            trieNode *k = p->next[c];
            k->pass--;
            if (k->pass == 0)
            {
                while (i < sz)
                {
                    int c = word[i++] - 'a';
                    trieNode *net = k->next[c];
                    k->next[c] = nullptr;
                    free(k);
                    k = net;
                }
            }
        }
    }

    bool search(string word)
    {
        int sz = word.length();
        trieNode *p = &root;

        for (int i = 0; i < sz; i++)
        {
            int c = word[i] - 'a';
            trieNode *k = p->next[c];
            if (k == nullptr)
            {
                return false;
            }
            p = k;
        }

        return p->end;
    }

    int prefixNumber(string pre)
    {
        int sz = pre.length();
        trieNode *p = &root;

        for (int i = 0; i < sz; i++)
        {
            int c = pre[i] - 'a';
            trieNode *k = p->next[c];
            if (k == nullptr)
            {
                return 0;
            }
            p = k;
        }

        return p->pass;
    }

    vector<string> trieU(vector<vector<string>> &operators)
    {
        vector<string> ans;
        for (int i = 0; i < operators.size(); i++)
        {
            int op = stoi(operators[i][0]);
            string s = operators[i][1];

            if(op == 1)
            {
                insert(s);
            }
            else if(op == 2)
            {
                deletes(s);
            }
            else if(op == 3)
            {
                if (search(s))
                {
                    ans.push_back("YSE");
                }
                else
                {
                    ans.push_back("NO");
                }
            }
            else
            {
                ans.push_back(to_string(prefixNumber(s)));
            }
        }
    }
};