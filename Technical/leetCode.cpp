#include "leetCode.h"
//  Ex, 802

void FindEventualSafeStates::show(vector<vector<int>>& table) const {
    for(const auto& r : table){
        for(const auto& c : r){
            std::cout << c<<" ";
        }
        cout<<endl;
    }
}
vector<int> FindEventualSafeStates::eventualSafeNodes(const vector<vector<int>>& graph){
    vector<vector<int>>table(graph.size(), vector<int>(graph.size(),0));
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            table[i][graph[i][j]] = graph[i][j];
        }
    }
    show(table);
    vector<int>result;

    return result;
}
bool CanConstruct::canConstruct(string s, int k) {
    // use bitset library
    bitset<128> hm;
    if(k > s.size()) return false;
    for(char c : s) hm.flip(c);
    return hm.count() <= k;
}

bool CountPrefixAndSuffix::isPrefix(const string& str1, const string& str2){
    auto res = std::mismatch(str1.begin(), str1.end(), str2.begin());
    return res.first == str1.end();
}

bool CountPrefixAndSuffix::isSuffix(const string& str1, const string& str2){
    int minLength = min(str1.length(), str2.length());
    for(int i = 1; i <= minLength; ++i){
        if(str1[str1.length()-i] != str2[str2.length()-i])
            return false;
    }
    return true;
}
bool CountPrefixAndSuffix::isPrefixAndSuffix(string& str1, string& str2){
    return (isPrefix(str1, str2) && isSuffix(str1, str2));
}

int CountPrefixAndSuffix::countPrefixSuffixPairs(vector<string>& words) {
    int count=0;
    for(int i = 0; i < words.size()-1;i++){
        for(int j = i+1; j < words.size(); j++){
            if(isPrefixAndSuffix(words[i], words[j]))
                count++;
        }
    }
    return count;
}


// nối và sort
ListNode* MergeTwoListAndSort::merge(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    ListNode *dmp = new ListNode();
    dmp->next = l1;
    ListNode *tmp = l1;
    ListNode *prev = nullptr;
    while (tmp)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    prev->next = l2;
    return dmp->next;
}
int MergeTwoListAndSort::getMinVal(ListNode *all)
{
    int minVal = INT_MAX;
    ListNode *tmp = all;
    while (tmp != nullptr)
    {
        if (tmp->val < minVal)
        {
            minVal = tmp->val;
        }
        tmp = tmp->next;
    }
    return minVal;
}
void MergeTwoListAndSort::delNode(ListNode *&all, int val)
{
    ListNode *prev = nullptr;
    ListNode *tmp = all;
    while (tmp != nullptr)
    {
        if (tmp->val == val)
        {
            break;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp != nullptr)
    {
        if (prev == nullptr)
        {
            all = all->next;
        }
        else
        {
            prev->next = tmp->next;
        }
        delete tmp;
    }
}
ListNode* MergeTwoListAndSort::mergeAndSort(ListNode *l1, ListNode *l2)
{
    ListNode *all = merge(l1, l2);

    ListNode *newList = new ListNode();
    ListNode *dump = newList;
    while (all != nullptr)
    {
        int minVal = getMinVal(all);
        newList->next = new ListNode(minVal);
        newList = newList->next;
        delNode(all, minVal);
    }
    return dump->next;
}
void MergeTwoListAndSort::show(ListNode *al)
{
    ListNode *tmp = al;
    while (tmp != nullptr)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}

void MergeTwoList::merge(ListNode *list1, ListNode *list2)
{
    if (list1 != nullptr)
        list1->next = list2;
}
ListNode* MergeTwoList::getPos(ListNode *list1, int val)
{
    ListNode *list = list1;
    while (list != nullptr)
    {
        if (list->next != nullptr && list->next->val > val)
            return list->next;
        list = list->next;
    }
    return list;
}
bool MergeTwoList::isRightPos(ListNode *list1, ListNode *list2, ListNode *dmp)
{
    if (list1->val <= list2->val)
    {
        dmp = getPos(list1, list2->val);
        return true;
    }
    else
    {
        dmp = getPos(list2, list1->val);
        return false;
    }
}
ListNode* MergeTwoList::mergeTwoLists(ListNode *list1, ListNode *list2)
{
    // 1 2 4
    // 1 3 4
    if (!list1)
        return list2;
    if (!list2)
        return list1;
    bool *flg;
    ListNode *dmp = nullptr;
    ListNode *tmp1 = list1;
    ListNode *tmp2 = list2;
    flg = new bool(isRightPos(tmp1, tmp2, dmp));

    while (true)
    {
    }

    return dmp;
}
void MergeTwoList::deAllocate(ListNode *list1)
{
    if (list1)
    {
        ListNode *tmp = list1;
        list1 = list1->next;
        delete tmp;
    }
}
void MergeTwoList::recursiveDeAllocate(ListNode *list1)
{
    while (list1)
        deAllocate(list1);
}
string LenghOfLastWord::getLastString(string s)
{
    string tmp = "";
    for (int i = 0; i < s.size(); i++)
    {
        tmp += s[i];
        if (s[i] == ' ')
        {
            tmp = "";
        }
    }
    return tmp;
}

// delete space in head and tail
string LenghOfLastWord::trim(const std::string &s)
{
    // del space at start
    /* expression mean:
        /t -> tab
        /n -> newline
        /r -> go back start column
        /f -> from feed
        /v -> Vertical tab | Tab dọc
    */
    size_t start = s.find_first_not_of(" \t\n\r\f\v"); // find first character not of space or anything like this
    // Nếu chuỗi chỉ có khoảng trắng, trả về chuỗi rỗng
    if (start == std::string::npos)
        return "";

    // Loại bỏ khoảng trắng từ cuối chuỗi
    size_t end = s.find_last_not_of(" \t\n\r\f\v");

    return s.substr(start, end - start + 1);
}

int LenghOfLastWord::lengthOfLastWord(string s)
{
    string lastString = getLastString(trim(s));
    return lastString.size();
}

int TrianglePascal::combination(int n, int k)
{
    if (k == 0 || k == n)
        return 1;

    long long result = 1;
    for (int i = 1; i <= k; i++)
    {
        // new algorithm  to caculate combination when not use factory;
        result = result * (n - i + 1) / i;
    }
    return result;
}
vector<vector<int>> TrianglePascal::generate(int numRows)
{
    // declared size row of 2 - dimension of vector<vector<int>>
    vector<vector<int>> pascalTriangle(numRows);
    for (int i = 0; i < numRows; i++)
    {
        // with cell in row of pascalTriangle, we have to allocation with numb cell approciate.
        pascalTriangle[i] = vector<int>(i + 1, 1);
        for (int j = 0; j <= i; j++)
        {
            pascalTriangle[i][j] = combination(i, j);
        }
    }
    return pascalTriangle;
}
vector<int> PlusOne::plusOne(vector<int> &digits)
{

    for (int i = digits.size() - 1; i >= 0; i--)
    {
        if (digits[i] < 9)
        {
            digits[i] += 1;
            return digits;
        }
        digits[i] = 0;
    }
    // có tác dụng chèn 1 lên đầu như 9 -> [1,0];
    digits.insert(digits.begin(), 1);
    return digits;
}
vector<vector<int>> ForSum4::ForSum4New(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> result;
    // use set to avoid situation have the same value althought different index in array
    set<vector<int>> setTmp;
    if (n < 4)
        return result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; i++)
    {

        /*
            two if have been comments will be usefull if the task tell no the same value; I guess so
        */

        // if(i > 0 && nums[i] == nums[i+1]) continue;
        for (int j = i + 1; j < n - 2; j++)
        {
            // if(j > i+1 && nums[j] == nums[j-1]) continue;
            int left = j + 1;
            int right = n - 1;
            while (left < right)
            {
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[left] + (long long)nums[right];
                /*
                    because nums have bene sort so the value is increase each by index;
                    so if sum < target them the value left should be increase and opposite with right index

                */
                if (sum < target)
                {
                    left++;
                }
                else if (sum > target)
                {
                    right--;
                }
                else
                {
                    setTmp.insert({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;
                }
            }
        }
    }
    // access each elements in setTmp after that push_back it into result
    for (auto it : setTmp)
    {
        result.push_back(it);
    }
    return result;
}

int SingleNumber::singleNumber(vector<int> &nums)
{
    unordered_map<int, int> result;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        result[nums[i]]++;
    }
    for (const auto &it : result)
    {
        int x = it.second;
        if (x == 1)
        {
            return it.first;
        }
    }
    return 1;
}
// second way use operator ^= XOR
int SingleNumber::singleNumber(vector<int> &nums, bool f)
{
    int result = 0, n = nums.size();
    for (int i = 0; i < n; i++)
    {
        result ^= nums[i];
    }
    return result;
}
string StringLongestPalindrome::longestPalindrome(string s)
{
    int n = s.size();
    string result;

    if (n < 2)
        return s;
    for (int i = 0; i < n; i++)
    {
        // check if this string has size odd number;
        int left = i, right = i;
        // if it
        while (left >= 0 && right < n && s[left] == s[right])
        {
            left--;
            right++;
        }

        string oddPalindrome = s.substr(left + 1, right - left - 1);
        if (oddPalindrome.size() > result.size())
        {
            result = oddPalindrome;
        }

        // check even palindrome
        left = i, right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right])
        {
            left--;
            right++;
        }
        string evenPalindrome = s.substr(left + 1, right - left - 1);
        if (evenPalindrome.size() > result.size())
        {
            result = evenPalindrome;
        }
    }

    return result;
}
vector<vector<int>> ThreeSum::threeSum(vector<int> nums)
{

    vector<vector<int>> result;
    set<vector<int>> s;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; i++)
    {
        int left = i + 1;
        int right = n - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum < 0)
            {
                left++;
            }
            else if (sum > 0)
            {
                right--;
            }
            else
            {
                s.insert({nums[i], nums[left], nums[right]});
                left++;
                right--;
            }
        }
    }
    for (auto it : s)
    {
        result.push_back(it);
    }
    return result;
}
// delete duplicataes value on this linked list;
ListNode* LinkedList::deleteDuplicates(ListNode *head)
{
    if (!head) // check if head == nullptr
        return head;
    ListNode *tmp = head;
    set<int> repl; // filter unique value/ increase
    while (tmp)    // mean tmp != nullptr
    {
        repl.insert(tmp->val);
        tmp = tmp->next;
    }
    ListNode *result = nullptr;
    ListNode *tail = nullptr; // track the end of the list
    for (auto it : repl)
    {
        if (!result)
        { // check if First Node
            result = new ListNode(it);
            tail = result;
        }
        else
        {
            tail->next = new ListNode(it);
            tail = tail->next;
        }
    }
    return result;
}
/*
    Check if linked list have a cycle,
    LIne way thinking: When it have a cycle, it never end;
*/
// way 1:
bool LinkedList::hasCycle(ListNode *head)
{
    if (!head || !head->next)
        return false; // mean if head == nullptr or head->next == nullptr we will return false;
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != slow)
    {
        if (!fast->next || !fast->next->next)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}
// way 2:
bool LinkedList::hasCycleV2(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (!fast && !fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}
// remove elements has value equal with target (val)
ListNode* LinkedList::removeElements(ListNode *head, int val)
{
    if (!head)
        return head; // if head == nullptr return head
    ListNode *tmp = head;
    ListNode *dummy = new ListNode(0, head); // has mission to access user locate to head linked list
    ListNode *pre = dummy;
    while (tmp)
    { // do it when tmp != nullptr;
        if (tmp->val == val)
        {
            pre->next = tmp->next;
            ListNode *nTmp = tmp;
            tmp = tmp->next;
            delete nTmp;
            continue;
            // just delete node
        }
        else
        {
            pre = tmp;
            tmp = tmp->next;
            // just go to next step;
        }
    }
    // return head with dummy pointer
    head = dummy->next;
    delete dummy; // delete it because it hasn't usefull anymore hahahaha.
    return head;
}
void ExtendArray::setN()
{
    int n;
    cin >> n;
    this->n = n;
}
vector<int>& ExtendArray::getA()
{
    return this->A;
}
vector<int>& ExtendArray::getB()
{
    return this->B;
}
int ExtendArray::getN()
{
    return this->n;
}
void ExtendArray::inputArr(vector<int> &tmp)
{
    tmp.resize(n);
    for (int i = 0; i < getN(); i++)
    {
        cin >> tmp[i];
    }
}
void ExtendArray::mergeArr()
{
    for (int i = 0; i < B.size(); i++)
    {
        A.push_back(B[i]);
    }
    sort(A.begin(), A.end());
}
void ExtendArray::view() const
{
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
}
void MixPoison::pushMatrix()
{
    lineMatrix.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lineMatrix[i];
    }
    sort(lineMatrix.begin(), lineMatrix.end());
}
// sliding window approach
void MixPoison::silidingWindow()
{
    int max_mr = 1;
    int left = 0;
    // n is size
    for (int right = 0; right < n; right++)
    {
        // sum weight of 2 mushrom not greater than k weight
        while (lineMatrix[right] - lineMatrix[left] > k)
        {
            // because we sort it at input function
            // so we can plus one of left to increase el, end of condtion while
            left++;
        }
        max_mr = max(max_mr, right - left + 1);
    }
    cout << max_mr;
}
void Travel::input()
{
    cin >> t >> b >> n;
    matrix.resize(n, vector<int>(3, 0));
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cin >> matrix[i][j];
        }
        T.push_back(matrix[i][0]);
        C.push_back(matrix[i][1]);
        W.push_back(matrix[i][2]);
    }
}
/*
Approach
    Still don't know how it work?
*/
int Travel::process()
{
    // create Array bigger
    vector<vector<int>> dp(t + 1, vector<int>(b + 1, 0));
    for (int i = 0; i < n; ++i)
    {
        int time = T[i];
        int cost = C[i];
        int value = W[i];
        // duyet nguoc de tranh bi ghi nham
        for (int j = t; j >= time; --j)
        {
            for (int k = b; k >= cost; --k)
            {
                dp[j][k] = max(dp[j][k], dp[j - time][k - cost] + value);
            }
        }
    }
    // result
    int maxExpreience = 0;
    for (int j = 0; j <= t; ++j)
    {
        for (int k = 0; k <= b; ++k)
        {
            maxExpreience = max(maxExpreience, dp[j][k]);
        }
    }
    return maxExpreience;
}
/*
    Dynamic Programming
*/
/*
    simple input line when n is not declare clearly
*/
void LIS::input()
{

    if (n == 0)
        cin >> n;
    inputLine.resize(n);
    L.resize(n, 1);
    for (int i = 0; i < n; i++)
    {
        cin >> inputLine[i];
    }
}
/*
    O(N^2)
    L[i]: last index of subsequence longest end at index i
    with j < n and k < j
    L[j]: max(L[j], L[k]+1) with conditon: inputLine[j] > inputLine[k]
    we use k to browse elements before j.
*/
void LIS::process()
{
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < j; k++)
        {
            if (inputLine[j] > inputLine[k])
            {
                L[j] = max(L[j], L[k] + 1);
            }
        }
    }
    cout << *max_element(L.begin(), L.end()) << endl;
}
