#define ALPHABETS 26

struct TrieNode 
{
  struct TrieNode *children[ALPHABETS];
  bool isEndWord;
};

TrieNode *getNode()
{
  struct TrieNode *temp = new TrieNode;
  for (int i=0; i<ALPHABETS; i++)
    temp->children[i] = NULL;
  
  temp->isEndWord = false;
}

void insert(TrieNode *root, string key)
{
  TrieNode *p = root;
  for (int i=0; i<key.length(); i++)
  {
    int index = key[i] - 'a';
    if (!p->children[index])
      p->children[index] = getNode();
    
    p = p->children[index];
  }
  p->isEndWord = true;
}

bool search(TrieNode *root, string key)
{
  if (!root) return false;

  TrieNode *p = root;
  for (int i=0; i<key.length();i++)
  {
    int index = key[i] - '0';
    if (!p->children[index]) return false;
    
    p = p->children[index];
  }
  
  return (p != NULL and p->isEndWord); 
}

bool isEmpty(TrieNode *root)
{
  TrieNode *p = root;
  
  for (int i=0; i<ALPHABETS; i++)
    if(p->children[i])
      return false
  
  return true;
}

TrieNode *remove(TrieNode *root, string key, int depth)
{
  if (!root) return NULL;
  
  if (depth == key.length()) {
    if (root->isEndWord)
      root->isEndWord = false;
    
    if (isEmpty(root)) {
      delete (root);
      root = NULL;
    }
    
    return root;      
  }
  
  int index = key[depth] - '0';
  root->childern[index] = remove(root->childern[index], key, depth+1);
  
  if (isEmpty(root) and root->isEndWord) {
    delete (root);
    root = NULL;
  }
  
  return root;  
}


int main(void)
{
  struct TrieNode *root = getNode();

  
  insert(root, "abc");
  insert(root, "abd");
  insert(root, "mno");
  
  search(root, "abc") ? cout << "yes" : cout << "No" << endl; 

  remove(root, "abc", 0);
}
