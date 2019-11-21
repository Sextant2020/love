#include<iostream>
#include<vector>
using namespace std;
 
class qipan
{
public:
 qipan() {}
 ~qipan() {};
 
 
 //向上下左右，斜的方向
 char left(int x, int y)
 {//检查是否合适
 if (x >= 1 && x <= hight&& y - 1 >= 1 && y - 1 <= width)
 {
  return q[x][y - 1];
 }
 else {
  return 'F';
 }
 
 }
 char right(int x, int y)
 {
 if (x >= 1 && x <= hight&&y + 1 >= 1 && y + 1 <= width)
 {
  return q[x][y + 1];
 }
 else {
  return 'F';
 }
 
 }
 char up(int x, int y)
 {
 if (x - 1 >= 1 && x - 1 <= hight && y >= 1 && y <= width)
 {
  return q[x - 1][y];
 }
 else {
  return 'F';
 }
 
 }
 char down(int x, int y)
 {
 if (x + 1 >= 1 && x + 1 <= hight && y >= 1 && y <= width)
 {
  return q[x + 1][y];
 }
 else {
  return 'F';
 }
 
 }
 char left_up(int x, int y)
 {
 if (x - 1 >= 1 && x - 1 <= hight && y - 1 >= 1 && y - 1 <= width)
 {
  return q[x - 1][y - 1];
 }
 else {
  return 'F';
 }
 
 }
 char left_down(int x, int y)
 {
 if (x + 1 >= 1 && x + 1 <= hight && y - 1 >= 1 && y - 1 <= width)
 {
  return q[x + 1][y - 1];
 }
 else {
  return 'F';
 }
 
 }
 char right_up(int x, int y)
 {
 if (x - 1 >= 1 && x - 1 <= hight && y + 1 >= 1 && y + 1 <= width)
 {
  return q[x - 1][y + 1];
 
 }
 else {
  return 'F';
 }
 
 
 }
 char right_down(int x, int y)
 {
 if (x + 1 >= 1 && x + 1 <= hight && y + 1 >= 1 && y + 1 <= width)
 {
  return q[x + 1][y + 1];
 }
 else {
  return 'F';
 }
 }
 
 void init_cur() {
 h_cur = hang;
 l_cur = lie;
 
 }
 bool win()
 {
 bool WIN = false;
 char temp = q[hang][lie];
 
 //以上为例，每次先看上面的5个，假如一样，iter++；否则 break；再加上下的方向，同样iter++；最后iter+1==5,WIN=true;并且退出
 //各个方向重复，上下左右，斜着的。
 //赢了直接退出。
 //显示是谁赢了
 
 
 //左右
 int count_lr = 1;
 init_cur();
 for (int i = 0; i < 4; i++)
 {
 
  if (left(h_cur, l_cur) == temp)
  count_lr++;
  else
  break;
  l_cur--;
 
 }
 init_cur();
 for (int i = 0; i < 4; i++)
 {
 
  if (right(h_cur, l_cur) == temp)
  count_lr++;
  else
  break;
  l_cur++;
 
 }
 if (count_lr == 5)
  WIN = true;
 //上下
 int count_ud = 1;
 init_cur();
 for (int i = 0; i < 4; i++)
 {
 
  if (up(h_cur, l_cur) == temp)
  count_ud++;
  else
  break;
  h_cur--;
 
 }
 init_cur();
 for (int i = 0; i < 4; i++)
 {
 
  if (down(h_cur, l_cur) == temp)
  count_ud++;
  else
  break;
  h_cur++;
 
 }
 if (count_ud == 5)
  WIN = true;
 
 
 //左斜
 int count_lt = 1;
 init_cur();
 for (int i = 0; i < 4; i++)
 {
 
  if (left_up(h_cur, l_cur) == temp)
  count_lt++;
  else
  break;
  h_cur--;
  l_cur--;
 
 }
 init_cur();
 for (int i = 0; i < 4; i++)
 {
 
  if (left_down(h_cur, l_cur) == temp)
  count_lt++;
  else
  break;
  h_cur++;
  l_cur--;
 
 }
 if (count_lt == 5)
  WIN = true;
 
 //右边斜
 int count_rt = 1;
 init_cur();
 for (int i = 0; i < 4; i++)
 {
 
  if (right_up(h_cur, l_cur) == temp)
  count_rt++;
  else
  break;
  h_cur--;
  l_cur++;
 
 }
 init_cur();
 for (int i = 0; i < 4; i++)
 {
 
  if (right_down(h_cur, l_cur) == temp)
  count_rt++;
  else
  break;
  h_cur++;
  l_cur++;
 
 }
 if (count_rt == 5)
  WIN = true;
 
 return WIN;
 }
 
 
 void qipan_array()
 {
 for (int i = 0; i < hight; i++) {
  for (int j = 0; j < width; j++)
  q[i][j] = '+';
 }
 }
 
 
 void prin_qipan()
 {
 //打印二维数组；每一行要打印上行号，以及列号
 for (int i = 0; i <hight; i++)
 {
 
  for (int j = 0; j < width; j++)
  {
  cout << q[i][j] << " ";
 
  }
  cout << i;
  cout << endl;
 }
 
 for (int j = 0; j <width; j++)
 {
  cout << j << " ";
 }
 cout << endl << "________________________________" << endl;
 }
 int xiaqi(int player)
 {
 if (player == 1) {
  q[hang][lie] = '*';
 }
 else if (player == 2)
 {
  q[hang][lie] = '@';
 }
 else
  cout << "input player is wrong" << endl;
 return 0;
 }
 
 //初始化行列
 int gethang(int h)
 {
 
 hang = h;
 return 0;
 }
 int getlie(int l)
 {
 lie = l;
 return 0;
 }
 
 
 int h_cur;
 int l_cur;
 const int hight = 9;
 const int width = 9;
 int hang; int lie;
 char q[9][9];
};
 
int main()
{
 int hang, lie;
 qipan wzq;
 wzq.qipan_array();
 cout << "A 与B 玩五子棋" << endl;
 cout << "A use * and B use @" << endl;
 cout << "________________________________" << endl;
 for (int i = 0; i < 15; i++) {
 cout << "A 输入行： ";
 cin >> hang;
 cout << "A 输入列： ";
 cin >> lie;
 if (wzq.q[hang][lie] != '+')
  cout << "输入的行列数字已经有人占据了" << endl;
 else {
  wzq.gethang(hang);
  wzq.getlie(lie);
 
  wzq.xiaqi(1);
  wzq.prin_qipan();
  if (wzq.win())
  {
  cout << "A is winner" << endl;
  exit(0);
  }
 }
 //b 开始了
 cout << "B 输入行： ";
 cin >> hang;
 cout << "B 输入列： ";
 cin >> lie;
 if (wzq.q[hang][lie] != '+')
  cout << "输入的行列数字已经有人占据了" << endl;
 else {
  wzq.gethang(hang);
  wzq.getlie(lie);
 
  wzq.xiaqi(2);
 
  wzq.prin_qipan();
  if (wzq.win())
  {
  cout << "B is winner" << endl;
  exit(0);
  }
 }
 }
 return 0;
 
 
}