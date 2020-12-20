#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct data1
{
    int n, label;
    int *features;
} data;

typedef struct node1
{
    data *elements;
    int count;
    int filter_index;
    int filter_bit;
    struct node1 *left;
    struct node1 *right;
} node;

void initnode(node *n, data **element, int c)
{
    n->left = NULL;
    n->right = NULL;
    n->elements = *element;
    n->filter_index = -1;
    n->filter_bit = -1;
    n->count = c;
    return;
}

void init_subnode(node *n, data **element, int sign, int filter_index, int c)
{
    n->left = NULL;
    n->right = NULL;
    n->elements = *element;
    if (sign)
        n->filter_bit = 1;
    else
        n->filter_bit = 0;
    n->filter_index = filter_index;
    n->count = c;
    return;
}

double init_entropy(node *node_, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if ((node_->elements)[i].label)
            sum++;
    }
    double p = sum / (double)(n);
    return p * log2(1 / p) + (1 - p) * log2(1 / (1 - p));
}

double cal_entropy(node *node_, int n, int start_i)
{

    int o_o = 0, o_z = 0, z_o = 0, z_z = 0;
    for (int i = 0; i < n; i++)
    {
        if ((node_->elements)[i].features[start_i] == 1 && (node_->elements)[i].label)
            o_o++;
        else if ((node_->elements)[i].features[start_i] == 1 && (node_->elements)[i].label == 0)
            o_z++;
        else if ((node_->elements)[i].features[start_i] == 0 && (node_->elements)[i].label)
            z_o++;
        else
            z_z++;
    }
    double n1 = (o_o + o_z == 0 ? 0 : (double)(o_o + o_z)), n2 = (z_o + z_z == 0 ? 0 : (double)(z_o + z_z));
    double p1 = (o_o == 0 ? 0.001 : (double)(o_o) / n1), p2 = (o_z == 0 ? 0.001 : (double)(o_z) / n1);
    double p3 = (z_o == 0 ? 0.001 : (double)(z_o) / n2), p4 = (z_z == 0 ? 0.001 : (double)(z_z) / n2);
    double entropy = (n1 / n) * (p1 * log2(1 / p1) + p2 * log2(1 / p2)) + (n2 / n) * (p3 * log2(1 / p3) + p4 * log2(1 / p4));
    return entropy;
}

int choose_lowent(node *node_, int n, int start_i, int f_n, int *check)
{

    double m = 1.1;
    int choose = -1;
    for (int i = start_i; i < f_n; i++)
    {

        double e = cal_entropy(node_, n, i);

        printf("%lf ", e);

        if (e <= m && !check[i])
        {
            choose = i;
            m = e;
        }
    }
    printf("choose: %d\n", choose);
    return choose;
}

int branching(node *node_, int n, int index, int *check)
{

    int z = 0, o = 0, lo = 0, lz = 0;
    for (int i = 0; i < n; i++)
    {
        if ((node_->elements)[i].label == 1)
            lo++;
        else
            lz++;
        if ((node_->elements)[i].features[index])
            o++;
        else
            z++;
    }
    if (!lz || !lo)
    {
        return 0;
    }
    if (!z || !o)
    {
        return 0;
    }
    data *datao = (data *)malloc(o * sizeof(data));
    data *dataz = (data *)malloc(z * sizeof(data));
    z = 0, o = 0;
    for (int i = 0; i < n; i++)
    {
        if ((node_->elements)[i].features[index])
        {
            datao[o++] = (node_->elements)[i];
        }
        else
        {
            dataz[z++] = (node_->elements)[i];
        }
    }

    node *l_node = (node *)malloc(sizeof(node)); // l=1
    node *r_node = (node *)malloc(sizeof(node)); // r=0
    node_->left = l_node, node_->right = r_node;
    init_subnode(l_node, &datao, 1, index, o);
    init_subnode(r_node, &dataz, 0, index, z);
    return o;
}

void recurse(node *node_, int n, int start_i, int f_n, int *check, int depth)
{

    //choose_lowent(node* node_, int n, int start_i, int f_n)
    //branching(node* node_, int n, int index)
    //printf("%d depth \n",depth);
    if (n == 1)
        return;
    //

    //
    int index = choose_lowent(node_, n, start_i, f_n, check);
    if (index == -1)
        return;
    //printf("index: %d\n",index);
    check[index] = 1;
    int oc = branching(node_, n, index, check);
    //printf("o, n: %d, %d\n",o,n);
    if (oc < n && oc)
    {
        //printf("making\n");
        recurse(node_->left, oc, start_i, f_n, check, depth + 1);
        recurse(node_->right, n - oc, start_i, f_n, check, depth + 1);
    }
    return;
}

int belongto(data k, node *node_)
{

    int ans;
    if (node_->left != NULL)
    {
        int filter_i = node_->left->filter_index;
        int filter_b = node_->left->filter_bit;
        if (k.features[filter_i] == filter_b)
        {
            ans = belongto(k, node_->left);
        }
        else
        {
            ans = belongto(k, node_->right);
        }
    }
    else
    {
        int sum = 0;
        for (int i = 0; i < node_->count; i++)
        {
            if ((node_->elements)[i].label == 0)
                sum++;
        }
        if (sum >= ((node_->count) - sum))
            return 0;
        else
            return 1;
    }
    return ans;
}

/*
void dfs_(node *node_){

  if(node_ == NULL) return;
  //printf("index num: %d %d\n",node_->filter_index, node_->filter_bit);
  dfs_(node_->left);
  dfs_(node_->right);
  return;
}

*/

int main()
{

    FILE *fp = fopen("data.txt", "rt");
    int n, f_n;
    fscanf(fp, "%d %d", &n, &f_n);
    data *d = (data *)malloc(n * sizeof(data));
    int *check = (int *)malloc(f_n * sizeof(int));
    for (int i = 0; i < f_n; i++)
        check[i] = 0;
    for (int i = 0; i < n; i++)
    {
        d[i].features = (int *)malloc(f_n * sizeof(int));
        for (int j = 0; j < f_n; j++)
        {
            fscanf(fp, "%d", &d[i].features[j]);
        }
        fscanf(fp, "%d", &d[i].label);
    }

    node *root = (node *)malloc(sizeof(node));
    initnode(root, &d, n);
    //int s_i = choose_lowent(root, n,0,f_n);
    //branching(root,n,s_i);

    recurse(root, n, 0, f_n, check, 0);
    //if(root->left->left == NULL) printf("yes");
    //dfs_(root);
    fclose(fp);
    int tc; //tc = 28
    FILE *tp = fopen("test.txt", "rt");
    fscanf(fp, "%d", &tc);

    data *td = (data *)malloc(tc * sizeof(data));
    for (int i = 0; i < tc; i++)
    {
        td[i].features = (int *)malloc(f_n * sizeof(int));
        for (int j = 0; j < f_n; j++)
        {
            fscanf(fp, "%d", &(td[i].features[j]));
        }
        int label = belongto(td[i], root);
        td[i].label = label;
    }
    FILE *tf = fopen("output.txt", "wt");

    for (int i = 0; i < tc; i++)
    {
        fprintf(tf, "%d\n", td[i].label);
    }

    fclose(tp);
    /*
  for(int i = 0 ; i < 7; i++){
    for(int j = 0;j < f_n;j++){
      printf("%d ",(root->left->elements)[i].features[j]);
    }
    printf("\n");
  }
  */

    for (int i = 0; i < n; i++)
    {
        free(d[i].features);
    }
    free(d);
    return 0;
}
