
//���ݿ� (��Ҫ�Ƕ������в���)  

//���̶߳����(һ�����������ж���̣߳��̼߳��ͬ������(������Mutex�����ź���)�����̼����Դ��������)   

//TCP/IP(  ���������Ĵλ��� sockeͨ��) �����ӵ����ݴ��� 


//���̺߳Ͷ���̴�������   ����ͨ��Э��   ���ݿ��ǳ��ʵļ��� 

��ֹ���ֶ��⾺����Դ���   c++���û�����ִ��mutex lock unlock

ʹ��lock_guard<std::mutex> guard(smoe_mutex) 

���ڽ��̵Ķ�������ʱ����Ĳ���ִ��
�����̵߳Ķ�������ʱͳһ�����Ƭ�εĲ���ִ�� 

#include <pthread.h> posix�߳� 
//�����߳�id(&)  �̲߳���(һ��ΪNULL)   ���ú���   ����ĺ������� 
int ret = pthread_create(&tids[i],null,func,null) 
��������ָ�� ת������ָ��
�����ú궨��#define NUM_THREADS 5 
func ��������Ϊ void* ������   ��������ݲ���(void *) &td[i] ǿ��ת��������

����pthread_join�ӳ����谭���ó��� ֱ��ָ����threadid�߳�Ϊֹ  ���� pthread_detach 
funcһ������
void *func(void *t){
	
	
	pthread_exit(NULL);
} 

c++ 11֮�����˱�׼�߳̿� thread  ---this_thread   get_id 
thread t(func) 
t.join()
  �����ͷ������������� 
  
  
�ͻ���(socket connect write read close) 
socket()��������socket
connect() ���ӷ�����
recv/send() ���պͷ�������
close() �ر�socket 

�����(socket  bind listen accept read write close) 
socket()��������socket������tcp�׽���
bind()�󶨷������˿ڣ����׽��ְ󶨵����صĵ�ַ�Ͷ˿���
listen()�����ͻ�������accept()��������
recv/send���ռ���������
close()�ر�socket 

socketͨ�ţ�����һ����̽ӿ�api tcp/ipЭ����Ҫ�򿪷����ṩ�����翪���õĽӿڣ�
����tcp/ipЭ������ͨ�ŵķ�װ
tcp/ip :Ӧ�ò�http ftp smtp�������tcp udp�������ip arp ·��������·����̫�� ����
 
 socket:read /write;send/recv;readv/writev;recvmsg/readmsg���Ƽ���;recvfrom/sendfrom;
 
  /////////////////��������    ������� 
  �ͻ��������˷���һ��SYN J  �ͻ��˴���connect���������� 
  �������ͻ�����Ӧһ��SYN K ����SYN J����ȷ��ACK J+1
  �ͻ����������������һ��ȷ�� SCK K+1
  
  ///�Ĵλ��� 
  ���̵���close�����رգ���ʱtcp����һ�� FIN M
  ��һ�˽�����FIN Mִ�б����رգ����������ȷ�ϣ����Ľ���Ҳ��Ϊ�ļ����������ݸ�Ӧ�ý���
  һ��ʱ��󣬽����ļ���������Ӧ�ý��̵���close�ر�����socket�������tcpҲ����һ��FIN N
  ���������FIN ��ԭ���Ͷ˶�������ȷ�ϣ������ر� 
  ---����ÿ��������һ��FIN��ACK 

\
void func(char *b,int *a); 
char b[] = "aaa";
int a = 0��
int*p = &a; 

func(b,p)


//void��������ֵ 
void������û�з���ֵ�ģ���ô���ڴ���Ĳ����ڼ��㴦��֮����ô�ѽ�������أ�
�������������õķ�ʽ��ָ������ã���Ҳ�����������ʵ��ʹ�õķ�ʽ��-----���Լ����ڴ棬����� 





1.����̲�������  ---���ͬʱ�������
�߳��ǿ�ִ�д���Ŀɷ��ɵ�Ԫ�����н���������һ���̣߳����Ƕ������ 
�߳̾��ǰ�һ�����̷ֳɶ��Ƭ�Σ�ÿ��Ƭ�ο�����һ������������
����̿����ȶ��߳�Ҫ��

�̻߳Ṳ�������ȫ�����Ͷѣ�˽���̵߳Ŀռ�����Ҫ����ջ�ͼĴ���
��֤�̰߳�ȫ������
 
���̼��ͨ�ţ��ܵ����ź��������ģ������ڴ� ���׽ӿ�  ��Ϣ����

���߳����ݹ������־�������  �������� ����Դ����� 




 

����ת�ַ��� +��0�� ����char buf[10] = " ";����յ��ַ��� 
�ַ���ת���� -��0�� 

������ʱ����char�ͣ�Ȼ���� �������β������str�� 

*str <'0' >'9'

*str -'0' ���ַ���  ת����ֵ 
cin.getline(p,20����ַ���) 
char * strdestcopy  = strdest

*strdest++=*strsrc++ !-'\0'
char*  return strdestcopy   

����ַ������� int len 

size_t size-------memcpy �ڴ濽�� 
 
�������ݲ�ͬ��strcpy�����ַ��� ����memcpy���Ը����������ݡ�
���Ʒŷ���ͬ��ǰ�߲���Ҫָ������   ������Ҫָ������
��;��ͬ 

assert(NULL!=src)//�ж�src�Ƿ���Ч
cosnt char* temp = src;//��ס�׵�ַ
while(*src++!='\0');//�����������˳�
return(src-temp-1);//βָ���ͷָ��֮�� Ч�ʸ�

//�Ӵ�����
whiel *src
//�ڲ�ѭ��
bp =src
sp =sub;
whiile *bp++=*sp++
	if(!*sp chazahodao �Ӵ�����Ϊֹ)
	return src
	
	src+=1��//��� ��ǰ�ƶ���λ 

return NULL 

--�ַ�����ת char src
char *start = src,*end =src.*p=src


whiel *p++
if *p=''huuozhe \0''
end =ptr-1//ָ��ĩβλ��
��ststa=end=p+1  


zhengti���巭ת  strrt=src end=ptr-2
whiel start<end
swap 9*strse++ ,*end-- 

xian��ȫ�� �پֲ�  �������Ⱦֲ� ��ȫ�ֶ����� 

�����ж� 
len 
if*(str+i)==*(str+len-i+1) 

zifu�ַ����Ƚ� 
itn ret =0
while(!(ret =*(unsigned char*)src-*(unsinged char*)dst)&&*dst){

		++src;
		++dst;
}
if ret<0 ret=-1
else if  ret>0 ret=1;
return ret


��󹫹��Ӵ� 

����  shortst  longst ��̺���� ���Ӵ� sub 

return substr 

��char*��malloc(sizeof(char)*(strlen(shortstr)+1)) ;����Ӵ��ַ��������ڴ����� 

ת���ַ����Ͳ����ַ�������
 

tmp = new char[strlen(strr)+1]
char = str[i]
str[i]= str[len-i-1]
str[len-i-1]=char 

return tmp

�������c++��c�ĳ���  �����������ı������  ����һ�ַ��ͱ������ 

����  ��д��ȥ��һ�㻯�����ظ�ʹ�õ��㷨����Ч��
c++ʹ��ģ����ʵ�� 
���������һ���µ�˼��  ����ģ�弼������Ч�Ľ��㷨�����ݽṹ���룬����ģ��֮�����϶� 

template <class T>//<typename T> ��ģ��

T func(T a,T,b){
	return a>b?a:b;
}
ʹ�÷������ �ܹ���������Ӵ��������� 

��ģ����Ӹ߼�����ͬ���빹����ͬ����ģ��Ķ���ͺ���ģ��Ķ�������
 ����ģ���ģ�庯������ģ���ģ���� 


����ģʽ

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

��׼��STL ����container ������ itertor itertor �㷨 algorithim algorithim 

�������� vector string deque' list
��������  set multiset map nultimap
������   stack  queue priority_queue' 

hash��   algorithim 

vector�ڲ�ʹ�ö�̬����ʵ��  �ڲ�ʹ��aocator�����ڴ����
 

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

vector �൱������    list�൱��˫������ 
set���治�����ظ�����
map  ��ֵ���ж�Ӧ  map(int ,string) mapstrinh;
mapsting.insert(pair<int,string>(1,"string "))) 
map�ڲ�ʵ��   ƽ�������  �����    ����Ҷ�ӽ��գ������λ�� 

hashmap  ��ϣ�� �������ƽ��ʱ�临�ӶȽӽ�����
map Ԫ�ؿ��԰��ռ�ֵ�������� 

stl������algorithim  �������㷨 

����  STL���� ��  ���ݿ�ϵͳ  ����ʽӦ��  ����Ҫ��̬�ڴ���� 

����ָ�� auto_ptr 




 

λ�����  ������������ض�λ  &��| �����������   ����^��� ~�� 
& ��������1����1 --����   ȡһ������ָ��λ 
| ��1��1����1 ---ĳЩλ��ֵ1 
^ ��ͬΪ0����ͬΪ1 --��ת ����ԭֵ 

�߼������  && || ����  ��  ��
&& �������Ϊ��
|| ��һ��Ϊ���Ϊ��
��ȡ�� 


�з��ź��޷��Ŵ���  --- �з���ֱ��ת���޷��� 


�ַ�������-- puts���  gets����  strcat����  strcpy  strlen 
���������͵���ֵת���ַ��� -- itoa ltoa ultoa gcvvt ecvt fcvt 
����% + '0'   10*temp -'0' �ַ���ת���� -��¼��һ���Ƿ��������� 

�ַ���ת����--atof atoi atol strtod strtol strtoul  

strcpy   copy *str++ = *str1++ !='\0' 

int len(const char* str){
	const char *p = str;
	while(*str++��='\0');//һֱѭ�� ������һ����ַ
	return (str-p - 1);//Ԫ�ظ��� 
}

memcpy(void *m1,void *m2,size_t size) 
{
	while(size-->0){
		*m1++=*m2++;//���� 
	}
	return m1; 
}

�������� ���Ʒ�ʽ  ��;��ͬ 

ʵ���ַ����Ӵ�����  --����˫ѭ��
ocnst char b
const char a
//��������Ȼ��������ʱ���� �����ڲ�ѭ������ 
���һ���������û���ҵ�����ԭ�ַ�����ǰ��1 


�ַ�����ת
void revc(char *str){
	if(str==NULL)
		return NULL;
	char *beg =str,*end=str;*p=str;
	while(*p++!='\0')
	{
		if(*p == ','||*p=="\n")
		{
			end = p-1;//ָ���һ�����ʽ�β 
			while(beg<end){
			swap(*beg++,*end--);
			} 
			beg=end=p+1;
		}
	}	
	//���巭ת
	beg = str,end =p-2;
	while(beg<end){
		swap(*beg++,*end--);
	} 
} 
len =strlen(str);
i=0;i<len/2;i++
*(str+i)==*(str+len-i-1)

ret = *(unsigneg char*)s1-*(unsigned char*)s2&&*s2



����������Ӵ� --Ҳ����Ҫ������ʱ������s1 s2  ����̵ĺͳ���
�Ӷ̵�������ҳ��ġ��� 

�ַ����в�����ֵ   ��������ó���  newһ���µĴ洢  

cahr *tem = new char[len=+1]
char c = tem[i] 
tmp[i]=tmp[len-i-1]
return tmp;

int temp,temp1

if(*str==0)
*mxa0++
if (*(++str)==1)
if temp<*max0
temp0 = max0��
max0=0


UL�޷��ų����� 

��ѭ�� 
while(1)  {}

for(;;){
}

Loop:
	...
goto Loop; 

�޷��ź��з�����һ������ʱ��ֱ��ת�����޷��š� 

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




//���غ͸�д

���أ������д���� ��дһ�������к���ͬ�����ǲ�����ͬ�ķ���
(��������ͬ�������б���費��ͬ��˳���޹أ��������Ϳ��Բ�ͬ)
��д����������д������麯��
(ֻ���麯�����ܸ�д����ͬ�������������б�ͷ���ֵ����) 

������һ���﷨�����б���������׶���ɣ��������������
��д�������н׶ξ����ģ���������̵���Ҫ����(��̬�ĵڶ�����ʽ) 



�̳кͶ�̬��c++�����������Ĳ�����
�̳���ʹ���������ܹ���û���ĳ�Ա���ݺͷ�����ֻ��Ҫ�������������ӻ���û�еĳ�Ա
��̬�ǽ����ڼ̳л����ϣ��Ƕ�̬�󶨣��Ǹ���Դ����������ķ�����


 �̳�������� public  private protected ���ּ̳з�ʽ��
 ���ּ̳еķ�ʽ ��ҪӰ�����������Զ���ļ̳���� 

��̬  ��װ  �̳� ��������
���ֶ�̬ 
�����̬��ͨ������ʵ��  ϵͳ�ڱ����ʱ����ݴ��ݲ������������͵Ⱦ���ʵ�ֺ��ֲ��� 
���ж�̬���麯��  ���е�ʱ��������ִ�� 

�麯����ʵ��ͨ���麯������ʵ�� --һ����ָ��vtblռ��4���ֽ�
 
�ڻ��๹�캯����������ƣ���������Ʋ�ִ�� 

ȫ�ֵĴ�ֵ�ʹ����õ����� 

���ؼ̳У�����һ��������ָ��������࣬���־��Ƕ��ؼ̳� 
���ؼ̳п���ͬʱ�̳ж������ �����׳��ֶ�����
Ϊ�˽��һЩ����������ӵ��������������������ԡ� 




����������ʹ��麯��
������ж�̬
�ܶ�������౾�����ɶ��󲻺��� ������಻�ܹ�ʵ�����������崿�麯���ӿ��ܰ�������Ĺ�ͬ��Ϊ��ȡ����

������� ʹ��A *a������A a 

�麯���ʹ��麯��   ��ʽ��ͬ
					�麯�������������в����أ����麯����������
					���麯����ע���ǽӿ�ͳһ�ԣ�ʵ�����������
					
�߳�ͬ�����ź����ͻ�����(Mutex)
�߳�ͬ����ָ�߳�֮���һ����Լ��ϵ��һ���̵߳�ִ����������һ���̵߳���Ϣ
��û�õ���һ���߳���Ϣ�͵ȴ���ֱ������Ϣ�Ż���
�̻߳��⣺ָ�Թ���Ľ���ϵͳ��Դ�������̷߳���ʱ��������� 
 
ʹ��һ������ɶ�д��
��һ����ͬ��Դ�������дͬʱ������з��� ��ÿ��ֻ��ִ��һ�� 
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

 //�߳�˳���ӡ ABC 
��������3���ź���  s1 s2 s3 ����s2��s1 post  s3��s2 post s1��s3 post

��A�߳̿�ʼ �����̵߳ȴ� 
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
		iter->join();//�̵߳ȴ� 
	}
	return 0;
}


 

//�����ĸ�����������  ���в��ȴ�  ���ɰ���  ���εȴ�
 //��������  �����ض���˳�������Դ �������ĳ�ʱʱ���
 
  ����ռ���ڴ�Ƚϴ� ��ϵͳΪ���̷����ڴ�  ����Ϊ�̷߳����ڴ�
   

TCP��UDP  
tcp ��ģʽ   udp���ݱ�ģʽ
��֤�����ȶ�     ����֤
����            ������

udp
 �������ݴ���Ƕ���Ϣ��ӵ�д���Client ���ݰ�ȫ��Ҫ�� 

������ �����ݺ�ָ������������� 

����������
node *rev(node* head){
	node*p,*q,*r;
	p = head->next;
	q = p->next;//����ڶ����ڵ� 
	p->next=NULL
	while(p!=NULL){//�������ڵ��nextָ�뷴ת 
		r = q->next;
		q->next =p;
		p = q;
		q = r; 
	}
	head->next = p;//�µĵ�һ���ڵ�Ϊԭ��ĩ�ڵ� 
	return heda;
} 

typedef struct node{
	int data;
	node *next;
}node; 
ѭ������  ����ָ��  һ����1 һ����2 �������Ϊ�յĻ������������ʱ���ʹ���ѭ������֮������ѭ��

����ϲ�
�鿴�̵Ĳ��뵽���ĵ��� 

node *memert(node*p1,node*p2){
	node *p = p1;
	node *q =NULL;//ʼ��ָ��p֮ǰ�Ľڵ� 
	
	if(p.data<p2.data &&p!null)
	{
		q=p;
		p = p.next;
	}
	if(p==p1){
		p2.next =p;
		return p2;
	}
	//���뵽�м�
	q.next =p2;
	p2.next=p;
	return head; 
	
} 

head = head1;
head-> next = m(head1->n)

��ȡ����ĳ���ֵ 
node *p = head
p = p.next
p!=NULL;���ж��Ƿ����

 ˫������ �ֳ�������������left��right ����ָ��
  
���е����  ���� �ⳤ ��ӡ�� 

typedef struct _Node{
	inr data;
	struct _Node *next;
}node; 
typedef struct myqueue{
	node*front;
	node*rear;
}mqueue;

���� �Ƚ��ȳ�    ջ �Ƚ���� 

node *newnode = (node*)malloc(sizeof(node))//�½��ڵ�
 �ж�ԭ�ڵ��Ƿ�Ϊ�� ������������Ϊ��  ����ͷ��β��Ϊ�½ڵ㣬������ڶ���β��
  ����  �Ƚ��ȳ�
  q_front = q-front-next
  ��ɾ�������Ϊ��  �򽫶���β�ÿ� 
  Ȼ�� free(node) 
 return q;

��������   pnode��=q-next 

���к�ջ�������Ƚ��ȳ�  ���Ƚ����   ��� ����  ��ջ��ջ 


����ʵ��ջ  ��������
���� �Ƚ��ȳ�
ջ   �Ƚ����

q1��123��Ȼ�����23�������q2.Ȼ���ӡ����q1��ֵ��
         Ȼ���ж�q1�Ƿ�Ϊ�գ�����ǽ�q2��3���ӷ���q1
		 ��ӡq2��ֵ 

������   ǰ �� ��  ��� 
ǰ��������
�У������
�����Ҹ�
 



















 







*max0 = temp//����󱣴�Ķ��� 
*max1 = temp1 

�����и�ֵ   

































�ڴ���䷽ʽ��--��̬�洢��   ջ  �ѵ��ڴ����
��̬-ȫ�ֱ���  �����ʱ����Ѿ��������
ջ -ִ�к���ʱ�������ھֲ����� 
���Ϸ���--��̬�����ڴ� 


c++Windows �е�HANDLE ��� file in>> out<< 
windows ��һ���������ڴ�Ϊ�����Ĳ���ϵͳ  HANDLE hInstance  



c++�е����������ת��  const  dynamic reinterpret--ָ��ת����ָ������ static  

�궨����������
#deifne YESR(10*60*324*29)UL ���޷���ѧ   unsigned long 

�з��ź��޷�����һ��   �з���ֱ��ת�����޷��� 

static ��������--������̬���� ���ù��̱��ֲ���
		ģ���ں�������--�൱�ڱ��ص�ȫ�ֱ��� ��ֻ�ܱ�ģ���ں������ã����ܱ���������
		ģ����--��̬����ֻ�ܱ��������ı��ط�Χ��ʹ�� 





