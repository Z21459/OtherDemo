#include <iostream>
using namespace std;


struct Node
{
	int data;
	Node* next;
};

class AllLink
{
public:
	Node* createLink();
	void addHeadNode(Node *head, int value);
	void addTailNode(Node *head, int value);
	void deleteHeadNode(Node *head);
	void deleteTailNode(Node *head);

	Node *searchNode(Node *head, int value);

	Node *reverse(Node* head);

	int lenLink(Node *head);
};

Node* AllLink::createLink()
{
	Node *head = new Node;
	head->next = nullptr;
	Node *temp,*q = NULL;
	int j = 0;
	for (int i = 1; i <= 5; i++)
	{
		temp = new Node;
		temp->data = i;
		if(++j == 1) head->next = temp;//只有一个元素
		else q->next = temp;//超过一个元素的时候 
		q = temp;
	}
	q->next = nullptr;
	return head;
}

int AllLink::lenLink(Node *head)
{
	Node *temp = head->next;//带头结点的指向第一个
	int len = 0;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	return len;
}

Node* AllLink::searchNode(Node *head,int value)
{
	Node *temp = head->next;
	while (temp)
	{
		if (temp->data == value) break;
		temp = temp->next;
	}
	return temp;
}



void AllLink::addHeadNode(Node *head, int value)
{
	Node* temp = head->next;
	if (!temp)//没有节点
	{
		Node*node = new Node;
		node->data = value;
		node->next = NULL;
		head = node;
	}
	else//有一个以上
	{
		Node *node = new Node;
		node->data = value;
		node->next = temp;
		head = node;
	}
}
void AllLink::addTailNode(Node *head, int value)
{

}

void AllLink::deleteHeadNode(Node *head)
{
	Node *node = head->next;
	if (!node) return;
	else
	{
		Node* temp = node->next;
		head = temp;
		delete node;
	}
}

void AllLink::deleteTailNode(Node *head)
{

}

//带头结点的 翻转
Node* AllLink::reverse(Node* head)
{
	Node *temp = head->next;
	if (!temp) return NULL;
	Node *p, *q, *r;
	p = head->next;
	q = p->next;
	p->next = NULL;
	while (q)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	head->next = p;//新的第一个节点是原来的最后一个节点

}


//创建窗口
#include <Windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain1(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("hello world");
	HWND hwnd;
	MSG msg;

	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadCursor(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
	wc.lpszClassName = szAppName;
	wc.lpszMenuName = NULL;
	if (!RegisterClass(&wc))
	{
		MessageBox(NULL, TEXT("This App"), szAppName, MB_ICONERROR);
		return 0;
	}
	//开始创建句柄窗口
	hwnd = CreateWindow(szAppName
		, TEXT("App")
		, WS_OVERLAPPEDWINDOW//风格
		, CW_USEDEFAULT
		, CW_USEDEFAULT
		, CW_USEDEFAULT
		, CW_USEDEFAULT
		, NULL
		, NULL
		, hInstance
		, NULL
	);
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hMainwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	char message[] = "press left";
	switch (msg)
	{
	case WM_PAINT:
	{
		hdc = BeginPaint(hMainwnd, &ps);
		GetClientRect(hMainwnd, &rect);//获得区域
		rect.bottom = rect.top + 50;
		DrawText(hdc, TEXT("world"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hMainwnd, &ps);
		break;
	}
	case WM_LBUTTONDOWN:
	{
		MessageBox(GetFocus(), message, "使用API创建窗口", MB_OK | MB_ICONINFORMATION);
		break;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);//退出
		break;
	}
	default:
		break;
	}
	return DefWindowProc(hMainwnd, msg, wParam, lParam);
}

