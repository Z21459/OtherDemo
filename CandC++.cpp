
//数据库 (主要是多个表进行操作)  

//多线程多进程(一个进程里面有多个线程，线程间的同步问题(互斥量Mutex锁和信号量)，进程间的资源死锁问题)   

//TCP/IP(  三次握手四次挥手 socke通信) 有连接的数据传输 


//多线程和多进程处理等情况   还有通信协议   数据库是常问的几种 

防止出现恶意竞争资源情况   c++采用互斥量执行mutex lock unlock

使用lock_guard<std::mutex> guard(smoe_mutex) 

基于进程的多任务处理时程序的并发执行
基于线程的多任务处理时统一程序的片段的并发执行 

#include <pthread.h> posix线程 
//创建线程id(&)  线程参数(一般为NULL)   调用函数   传入的函数参数 
int ret = pthread_create(&tids[i],null,func,null) 
将无类型指针 转成整形指针
善于用宏定义#define NUM_THREADS 5 
func 定义类型为 void* 的类型   传入的数据参数(void *) &td[i] 强制转换无类型

连接pthread_join子程序阻碍调用程序 直到指定的threadid线程为止  分离 pthread_detach 
func一般类型
void *func(void *t){
	
	
	pthread_exit(NULL);
} 

c++ 11之后有了标准线程库 thread  ---this_thread   get_id 
thread t(func) 
t.join()
  阻塞和非租塞两种类型 
  
  
客户端(socket connect write read close) 
socket()创建监听socket
connect() 连接服务器
recv/send() 接收和发送数据
close() 关闭socket 

服务端(socket  bind listen accept read write close) 
socket()创建监听socket，创建tcp套接字
bind()绑定服务器端口，将套接字绑定到本地的地址和端口上
listen()监听客户端连接accept()接收连接
recv/send接收及发送数据
close()关闭socket 

socket通信，其是一个编程接口api tcp/ip协议需要向开发者提供做网络开发用的接口，
他对tcp/ip协议网络通信的封装
tcp/ip :应用层http ftp smtp，传输层tcp udp，网络层ip arp 路由器，链路层以太网 网桥
 
 socket:read /write;send/recv;readv/writev;recvmsg/readmsg（推荐）;recvfrom/sendfrom;
 
  /////////////////三次握手    连接完成 
  客户端向服务端发送一个SYN J  客户端触发connect，触发请求 
  服务端向客户端响应一个SYN K 并对SYN J进行确认ACK J+1
  客户端再像服务器发送一个确认 SCK K+1
  
  ///四次挥手 
  进程调用close主动关闭，这时tcp发送一个 FIN M
  另一端接收了FIN M执行被动关闭，对这个进行确认，它的接收也作为文件结束符传递给应用进程
  一段时间后，接收文件结束符的应用进程调用close关闭它的socket。则其的tcp也发送一个FIN N
  接收这个的FIN 的原发送端对他进行确认，结束关闭 
  ---这样每个方向都有一个FIN和ACK 

\
void func(char *b,int *a); 
char b[] = "aaa";
int a = 0；
int*p = &a; 

func(b,p)


//void函数返回值 
void函数是没有返回值的，那么对于传入的参数在计算处理之后，怎么把结果返回呢？
这里给出两种最常用的方式：指针和引用！这也是软件开发中实际使用的方式。-----可以减少内存，代码简单 





1.多进程并发问题  ---多个同时进行情况
线程是可执行代码的可分派单元，所有进程至少有一个线程，但是多个任务 
线程就是把一个进程分成多个片段，每个片段可以有一个独立的流程
多进程开销比多线程要大

线程会共享进程中全局区和堆，私有线程的空间则主要包括栈和寄存器
保证线程安全加锁。
 
进程间的通信：管道，信号量，报文，共享内存 ，套接口  消息队列

多线程数据共享会出现竞争问题  共享数据 抢资源的情况 




 

数字转字符串 +“0” 放在char buf[10] = " ";定义空的字符串 
字符串转数字 -“0” 

定义临时的数char型，然后在 拷贝回形参里面的str中 

*str <'0' >'9'

*str -'0' 将字符串  转成数值 
cin.getline(p,20获得字符串) 
char * strdestcopy  = strdest

*strdest++=*strsrc++ !-'\0'
char*  return strdestcopy   

获得字符串长度 int len 

size_t size-------memcpy 内存拷贝 
 
复制内容不同。strcpy复制字符串 ，而memcpy可以复制任意内容。
复制放发不同。前者不需要指定长度   后者需要指定长度
用途不同 

assert(NULL!=src)//判断src是否有效
cosnt char* temp = src;//记住首地址
while(*src++!='\0');//遇到结束符退出
return(src-temp-1);//尾指针和头指针之差 效率高

//子串查找
whiel *src
//内层循环
bp =src
sp =sub;
whiile *bp++=*sp++
	if(!*sp chazahodao 子串结束为止)
	return src
	
	src+=1；//如果 向前移动移位 

return NULL 

--字符串翻转 char src
char *start = src,*end =src.*p=src


whiel *p++
if *p=''huuozhe \0''
end =ptr-1//指向末尾位置
我ststa=end=p+1  


zhengti整体翻转  strrt=src end=ptr-2
whiel start<end
swap 9*strse++ ,*end-- 

xian先全局 再局部  或者是先局部 再全局都可以 

回文判断 
len 
if*(str+i)==*(str+len-i+1) 

zifu字符串比较 
itn ret =0
while(!(ret =*(unsigned char*)src-*(unsinged char*)dst)&&*dst){

		++src;
		++dst;
}
if ret<0 ret=-1
else if  ret>0 ret=1;
return ret


最大公共子串 

定义  shortst  longst 最短和最长串 和子串 sub 

return substr 

（char*）malloc(sizeof(char)*(strlen(shortstr)+1)) ;存放子串字符串，堆内存申请 

转换字符串和插入字符串个数
 

tmp = new char[strlen(strr)+1]
char = str[i]
str[i]= str[len-i-1]
str[len-i-1]=char 

return tmp

泛化编程c++是c的超集  具有面向对象的编程能力  其是一种泛型编程能力 

泛型  编写玩去哪一般化并可重复使用的算法，其效率
c++使用模板来实现 
泛化编程是一种新的思想  基于模板技术，有效的将算法和数据结构分离，降低模块之间的耦合度 

template <class T>//<typename T> 类模板

T func(T a,T,b){
	return a>b?a:b;
}
使用泛化编程 能够极大的增加代码重用性 

类模板更加高级，相同代码构建不同的类模板的定义和函数模板的定义类型
 函数模板和模板函数，类模板和模板类 


单例模式

class signal{
	private:
		signal(){
		}
		public:
			static singnal *getinstance(){
				static signal instance;
				return &instance;
			}
}; 

标准库STL 容器container 迭代器 itertor itertor 算法 algorithim algorithim 

序列容器 vector string deque' list
关联容器  set multiset map nultimap
适配器   stack  queue priority_queue' 

hash表   algorithim 

vector内部使用动态数组实现  内部使用aocator进行内存管理
 

ifstream in(path)
if(!in)  error
int temp
while(!in.eof()) 
in>>temp;
data.push_bakc(temp;)
in.close
ofstream out
out << data[i]
out.close

vector 相当于数组    list相当于双向链表 
set里面不存在重复数据
map  键值进行对应  map(int ,string) mapstrinh;
mapsting.insert(pair<int,string>(1,"string "))) 
map内部实现   平衡二叉树  红黑树    所有叶子结点空，被标记位黑 

hashmap  哈希表 各项操作平均时间复杂度接近常数
map 元素可以按照键值进行排序 

stl里面有algorithim  里面有算法 

链表  STL容器 串  数据库系统  交互式应用  都需要动态内存分配 

智能指针 auto_ptr 




 

位运算符  可以设置清楚特定位  &和| 这两个运算符   还有^异或 ~非 
& 两个都是1才是1 --清零   取一个数中指定位 
| 有1个1就是1 ---某些位置值1 
^ 相同为0，不同为1 --翻转 保留原值 

逻辑运算符  && || ！与  或  非
&& 都是真才为真
|| 有一个为真就为真
！取反 


有符号和无符号存在  --- 有符号直接转成无符号 


字符串操作-- puts输出  gets输入  strcat连接  strcpy  strlen 
将任意类型的数值转成字符串 -- itoa ltoa ultoa gcvvt ecvt fcvt 
求余% + '0'   10*temp -'0' 字符串转数字 -记录第一个是否是正负号 

字符串转数字--atof atoi atol strtod strtol strtoul  

strcpy   copy *str++ = *str1++ !='\0' 

int len(const char* str){
	const char *p = str;
	while(*str++！='\0');//一直循环 获得最后一个地址
	return (str-p - 1);//元素个数 
}

memcpy(void *m1,void *m2,size_t size) 
{
	while(size-->0){
		*m1++=*m2++;//复制 
	}
	return m1; 
}

两者内容 复制方式  用途不同 

实现字符串子串查找  --两层双循环
ocnst char b
const char a
//外层遍历，然后利用临时变量 进行内部循环遍历 
如果一层遍历结束没有找到，则原字符串向前加1 


字符串翻转
void revc(char *str){
	if(str==NULL)
		return NULL;
	char *beg =str,*end=str;*p=str;
	while(*p++!='\0')
	{
		if(*p == ','||*p=="\n")
		{
			end = p-1;//指向第一个单词结尾 
			while(beg<end){
			swap(*beg++,*end--);
			} 
			beg=end=p+1;
		}
	}	
	//整体翻转
	beg = str,end =p-2;
	while(beg<end){
		swap(*beg++,*end--);
	} 
} 
len =strlen(str);
i=0;i<len/2;i++
*(str+i)==*(str+len-i-1)

ret = *(unsigneg char*)s1-*(unsigned char*)s2&&*s2



查找最大共有子串 --也是需要建立临时的两个s1 s2  保存短的和长的
从短的里面查找长的。。 

字符串中插入数值   。。。获得长度  new一个新的存储  

cahr *tem = new char[len=+1]
char c = tem[i] 
tmp[i]=tmp[len-i-1]
return tmp;

int temp,temp1

if(*str==0)
*mxa0++
if (*(++str)==1)
if temp<*max0
temp0 = max0；
max0=0


UL无符号长整形 

死循环 
while(1)  {}

for(;;){
}

Loop:
	...
goto Loop; 

无符号和有符号在一起计算的时候，直接转换成无符号。 

if(strign!null)
deltet [] strign
string = null
string::string(const char *str){
	
	 if str==unukl
 string=new cher[1]
 *stirgn='\0'
 else
 string =new char strlrn(str)+1
 strcpy(string str)
 
}

 
 string::string(const string &other){
 	 string=new char[stelen(otehre.string)+1]
 strcpy(string,othre.string)
 }




string& string::operator =(const string &other){
	if(this ==&other){
		return *this;
	}
	delete[]string;
	string = new char[strlen(other.string)+1];
	strcpy(string,other.string);
	return *this;
}




//重载和覆写

重载：子类改写父类 编写一个与已有函数同名但是参数表不同的方法
(方法名相同，参数列表必需不相同和顺序无关，返回类型可以不同)
覆写：派生类重写基类的虚函数
(只有虚函数才能覆写，相同函数名，参数列表和返回值类型) 

重载是一种语法规则，有编译器编译阶段完成，不是面向对象编程
覆写是有运行阶段决定的，面向对象编程的重要特征(多态的第二种形式) 



继承和多态是c++核心面向对象的操作。
继承类使得派生类能够获得基类的成员数据和方法，只需要在派生类中增加基类没有的成员
多态是建立在继承基础上，是动态绑定，是父类对代用子类对象的方法。


 继承三种情况 public  private protected 三种继承方式。
 三种继承的方式 主要影响子类的子类对对象的继承情况 

多态  封装  继承 三大特征
两种多态 
编译多态：通过重载实现  系统在编译的时候根据传递参数、返回类型等决定实现何种操作 
运行多态：虚函数  运行的时候决定如何执行 

虚函数的实现通过虚函数表来实现 --一个虚指针vtbl占用4个字节
 
在基类构造函数调用虚机制，子类虚机制不执行 

全局的传值和传引用的区别 

多重继承：允许一个派生类指定多个基类，这种就是多重继承 
多重继承可以同时继承多个基类 但容易出现二义性
为了解决一些事物往往会拥有两个和以上事物的属性。 




引入抽象基类和纯虚函数
方便进行多态
很多情况基类本身生成对象不合适 抽象基类不能够实例化，它定义纯虚函数接口能把派生类的共同行为提取出来

抽象基类 使用A *a而不是A a 

虚函数和纯虚函数   形式不同
					虚函数可以在子类中不重载，纯虚函数必需重载
					纯虚函数关注的是接口统一性，实现由子类完成
					
线程同步：信号量和互斥锁(Mutex)
线程同步：指线程之间的一种制约关系，一个线程的执行依赖于另一个线程的消息
当没得到另一个线程消息就等待，直到有消息才唤醒
线程互斥：指对共享的进程系统资源，各个线程访问时候的排他性 
 
使用一个锁完成读写锁
有一个共同资源，多个读写同时对其进行访问 ，每次只能执行一个 
count_mutex =0
write_mutex =0
read_mutex=0
 
void readlock(){
	lock(Mutex);
	read_count++;
	if(read_count==1)
		lock(write_mutex)
	unlock(Mutxe);
} 
void read_unlock(){
	lock(Mutex);
	read_count--;
	if(read-count==0)
		unlock(write_mutxe);
	unlock(n=mutex);
}
void writelock(){
	lock(write_mutex)
}
void writeunlock(){
	unlock(eritr_mutex)
}

 //线程顺序打印 ABC 
可以设置3个信号量  s1 s2 s3 其中s2由s1 post  s3由s2 post s1由s3 post

由A线程开始 其他线程等待 
#include<iostream>
#include<vector>
#include<thread>
#include<condition_variable>
using namespace std;
mutex mu;
std::condition_variable cond_var;
int num=0;
void func(char ch)
{
	int n=ch-'A';
	for(int i=0;i<10;i++)
	{
		std::unique_lock<std::mutex> mylock(mu);
		cond_var.wait(mylock,[n]{return n==num;});
		cout<<ch;
		num=(num+1)%3;
		mylock.unlock();
		cond_var.notify_all();
	}
}
int main()
{
	vector<thread> pool;
	pool.push_back(thread(func,'A'));
	pool.push_back(thread(func,'B'));
	pool.push_back(thread(func,'C'));
	for(auto iter=pool.begin();iter!=pool.end();iter++)
	{
		iter->join();//线程等待 
	}
	return 0;
}


 

//死锁四个条件：互斥  持有并等待  不可剥夺  环形等待
 //避免死锁  按照特定的顺序访问资源 设置锁的超时时间等
 
  进程占据内存比较大 ，系统为进程分配内存  不会为线程分配内存
   

TCP与UDP  
tcp 流模式   udp数据报模式
保证数据稳定     不保证
连接            无连接

udp
 网络数据大多是短消息，拥有大量Client 数据安全无要求 

单链表 ，数据和指针两个部分组成 

单链表逆置
node *rev(node* head){
	node*p,*q,*r;
	p = head->next;
	q = p->next;//保存第二个节点 
	p->next=NULL
	while(p!=NULL){//遍历各节点的next指针反转 
		r = q->next;
		q->next =p;
		p = q;
		q = r; 
	}
	head->next = p;//新的第一个节点为原来末节点 
	return heda;
} 

typedef struct node{
	int data;
	node *next;
}node; 
循环链表  两个指针  一个是1 一个是2 ，如果不为空的话，当两个相等时，就存在循环，反之不存在循环

有序合并
查看短的插入到长的当中 

node *memert(node*p1,node*p2){
	node *p = p1;
	node *q =NULL;//始终指向p之前的节点 
	
	if(p.data<p2.data &&p!null)
	{
		q=p;
		p = p.next;
	}
	if(p==p1){
		p2.next =p;
		return p2;
	}
	//插入到中间
	q.next =p2;
	p2.next=p;
	return head; 
	
} 

head = head1;
head-> next = m(head1->n)

求取链表的长度值 
node *p = head
p = p.next
p!=NULL;来判断是否可以

 双向链表 分成左右两个部分left和right 左右指针
  
队列的入队  出队 测长 打印等 

typedef struct _Node{
	inr data;
	struct _Node *next;
}node; 
typedef struct myqueue{
	node*front;
	node*rear;
}mqueue;

队列 先进先出    栈 先进后出 

node *newnode = (node*)malloc(sizeof(node))//新建节点
 判断原节点是否为空 ，如果是则队列为空  队列头和尾均为新节点，否则放在对垒尾部
  队列  先进先出
  q_front = q-front-next
  当删除后队列为空  则将队列尾置空 
  然后 free(node) 
 return q;

遍历队列   pnode！=q-next 

队列和栈的区别：先进先出  和先进后出   入队 出队  进栈出栈 


队列实现栈  两个队列
队列 先进先出
栈   先进后出

q1进123，然后出队23进入队列q2.然后打印队列q1的值；
         然后判断q1是否为空，如果是将q2的3出队放入q1
		 打印q2的值 

二叉树   前 中 后  层次 
前：根左右
中：左根右
后：左右跟
 



















 







*max0 = temp//将最后保存的东西 
*max1 = temp1 

最后进行赋值   

































内存分配方式，--静态存储区   栈  堆的内存分配
静态-全局变量  编译的时候就已经分配好了
栈 -执行函数时，函数内局部变量 
堆上分配--动态分配内存 


c++Windows 中的HANDLE 句柄 file in>> out<< 
windows 是一个以虚拟内存为基础的操作系统  HANDLE hInstance  



c++中的四种运算符转化  const  dynamic reinterpret--指针转其他指针类型 static  

宏定义声明常量
#deifne YESR(10*60*324*29)UL 长无符号学   unsigned long 

有符号和无符号在一起   有符号直接转换成无符号 

static 函数体内--声明静态变量 调用过程保持不变
		模块内函数体外--相当于本地的全局变量 ，只能被模块内函数调用，不能被其他调用
		模块内--静态函数只能被声明它的本地范围内使用 





