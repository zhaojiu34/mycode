#define _CRT_SECURE_NO_WARNINGS 1

n : = len(s)
//ip地址最小为：1.1.1.1
//最大为255.255.255.255
if n < 4 || n > 12 {
	return[]string{}
}

ans: = []string{}
//dfs进行回溯，开始遍历s的索引位置，path就是从这个索引遍历到的合法结果
var dfs func(start int, path[]string)
dfs = func(start int, path[]string) {
	//如果找到了4段ip地址或者s已经遍历完了，就用"."拼接然后返回结果
	if len(path) == 4 && start == n{
		ans = append(ans, strings.Join(path, "."))
		return
	}
		//如果还没有找到4段ip就遍历完了，那么就提前回溯
		if start == n{
			return
		}
			//由于ip地址不能有先导‘0’，所以如果当前数字为0，那么这一段ip地址就只能为0
			if s[start] == '0' {
				dfs(start + 1, append(path, "0"))
					return
			}
	//核心，从start开始，再往前走两个（一共三位）
	for i : = start; i < n&& i <= start + 2; i++ {
	s: = s[start:i + 1]
		//看一下遍历之后得到的s是否合法
		//合法就加入path，去找下一段
		if isValid(s) {
			dfs(i + 1, append(path, s))
		}
	}
}
//需要的结果就是从0开始递归
dfs(0, []string{})
return ans
}

//判断子字符串是否有效
func isValid(str string) bool{
	sum: = 0
	for _, c : = range str {
		//将字符串转化为数字
		sum = sum * 10 + int(c - '0')
	}
		//合法的取值范围是在1到255之间
		return sum <= 255 && sum > 0
}
