local function getupvaluetable(u, func, unique)
	local i = 1
	while true do
		local name, value = debug.getupvalue(func, i)
		if name == nil then
			return
		end
		local t = type(value)
		if t == "table" then
			u[name] = value
		elseif t == "function" then
			if not unique[value] then
				unique[value] = true
				getupvaluetable(u, value, unique)
			end
		end
		i=i+1
	end
end

return function(skynet, source, filename, args, ...)
	if filename then
		filename = "@" .. filename
	else
		filename = "=(load)"
	end
	local output = {}

	local function print(...)
		local value = { ... }
		for k,v in ipairs(value) do
			value[k] = tostring(v)--k 0 1 2 3 4
		end
		table.insert(output, table.concat(value, "\t"))
	end
	local u = {}--得到地址结果
	local unique = {}
	local funcs = { ... }
	for k, func in ipairs(funcs) do--获取接口的函数原型  保存在u里
		getupvaluetable(u, func, unique)
	end
	local p = {}
	local proto = u.proto
	if proto then
		for k,v in pairs(proto) do
			local name, dispatch = v.name, v.dispatch
			if name and dispatch and not p[name] then
				local pp = {}
				p[name] = pp
				getupvaluetable(pp, dispatch, unique)
			end
		end
	end
	--执行新的lua代码
	local env = setmetatable( { print = print , _U = u, _P = p}, { __index = _ENV }) --通过env里的 _U 和_P获得函数原型
	local func, err = load(source, filename, "bt", env)--加载新的lua代码  通过env里的_U和_P获得函数原型
	
	if not func then
		return false, { err }
	end
	local ok, err = skynet.pcall(func, table.unpack(args, 1, args.n))
	if not ok then
		table.insert(output, err)
		return false, output
	end

	return true, output
end
