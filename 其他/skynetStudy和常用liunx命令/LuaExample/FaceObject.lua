--面向对象操作
--通过基本结构table描述对象的属性和利用function表示方法

--一个简单的类 包含三个属性  area  length  breadth  printArea
--[[
--元类
Rect = {area=0,length=0,breadth=0}

--派生类的方法new
function Rect:new(o,length,breadth)
	o=o or {}
	setmetatable(o,self)
	self._index = self
	self.length = length or 0
	self.breadth = breadth or 0
	self.area = length*breadth;
	return o
end

--派生类的方法 printArea
function Rect:printArea()
	print("矩形面积",self.area)
end


r = Rect:new(nil,10,20)

print(r.length)
r:printArea()
]]--


--[[
-- 元类
Shape = {area = 0}

-- 基础类方法 new
function Shape:new (o,side)
  o = o or {}
  setmetatable(o, self)
  self.__index = self
  side = side or 0
  self.area = side*side;
  return o
end

-- 基础类方法 printArea
function Shape:printArea ()
  print("面积为 ",self.area)
end

-- 创建对象
myshape = Shape:new(nil,10)

myshape:printArea()
]]--



--[[
--继承 指一个对象直接使用另一个对象的属性和方法。可用于扩展基础类的属性和方法。
-- Meta class
Shape = {area = 0}
-- 基础类方法 new
function Shape:new (o,side)
  o = o or {}
  setmetatable(o, self)
  self.__index = self
  side = side or 0
  self.area = side*side;
  return o
end

--基础类方法
function Shape:printArea()
	print("面积为:",self.area)
end

--Square 对象继承了Shape类：
Square = Shape:new()
--Derived class method new
function Square:new (o,side)
	o =o or Shape:new(o,side)
	setmetatable(o,self)
	self._index =self
	return o
end
]]--



--完整实例 继承一个简单类 扩展派生类 派生类中保留了继承类的成员变量和方法
-- Meta class
Shape = {area = 0}
-- 基础类方法 new
function Shape:new (o,side)
  o = o or {}
  setmetatable(o, self)
  self.__index = self
  side = side or 0
  self.area = side*side;
  return o
end
-- 基础类方法 printArea
function Shape:printArea ()
  print("面积为 ",self.area)
end

-- 创建对象
myshape = Shape:new(nil,10)
myshape:printArea()

Square = Shape:new()
-- 派生类方法 new
function Square:new (o,side)
  o = o or Shape:new(o,side)
  setmetatable(o, self)
  self.__index = self
  return o
end

-- 派生类方法 printArea
function Square:printArea ()
  print("正方形面积为 ",self.area)
end

-- 创建对象
mysquare = Square:new(nil,10)
mysquare:printArea()

Rectangle = Shape:new()
-- 派生类方法 new
function Rectangle:new (o,length,breadth)
  o = o or Shape:new(o)
  setmetatable(o, self)
  self.__index = self
  self.area = length * breadth
  return o
end

-- 派生类方法 printArea
function Rectangle:printArea ()
  print("矩形面积为 ",self.area)
end

-- 创建对象
myrectangle = Rectangle:new(nil,10,20)
myrectangle:printArea()

--函数重写重写基础类 在派生类中实现方式
function Square:printArea()
	print("正方形面积",self.area)
end
