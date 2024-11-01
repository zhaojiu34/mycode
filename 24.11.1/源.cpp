#define _CRT_SECURE_NO_WARNINGS 1

n : = len(s)
//ip��ַ��СΪ��1.1.1.1
//���Ϊ255.255.255.255
if n < 4 || n > 12 {
	return[]string{}
}

ans: = []string{}
//dfs���л��ݣ���ʼ����s������λ�ã�path���Ǵ���������������ĺϷ����
var dfs func(start int, path[]string)
dfs = func(start int, path[]string) {
	//����ҵ���4��ip��ַ����s�Ѿ��������ˣ�����"."ƴ��Ȼ�󷵻ؽ��
	if len(path) == 4 && start == n{
		ans = append(ans, strings.Join(path, "."))
		return
	}
		//�����û���ҵ�4��ip�ͱ������ˣ���ô����ǰ����
		if start == n{
			return
		}
			//����ip��ַ�������ȵ���0�������������ǰ����Ϊ0����ô��һ��ip��ַ��ֻ��Ϊ0
			if s[start] == '0' {
				dfs(start + 1, append(path, "0"))
					return
			}
	//���ģ���start��ʼ������ǰ��������һ����λ��
	for i : = start; i < n&& i <= start + 2; i++ {
	s: = s[start:i + 1]
		//��һ�±���֮��õ���s�Ƿ�Ϸ�
		//�Ϸ��ͼ���path��ȥ����һ��
		if isValid(s) {
			dfs(i + 1, append(path, s))
		}
	}
}
//��Ҫ�Ľ�����Ǵ�0��ʼ�ݹ�
dfs(0, []string{})
return ans
}

//�ж����ַ����Ƿ���Ч
func isValid(str string) bool{
	sum: = 0
	for _, c : = range str {
		//���ַ���ת��Ϊ����
		sum = sum * 10 + int(c - '0')
	}
		//�Ϸ���ȡֵ��Χ����1��255֮��
		return sum <= 255 && sum > 0
}
