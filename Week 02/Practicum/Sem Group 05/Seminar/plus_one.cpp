//#include <iostream>
//#include <vector>
//
////Идея:
////добавяме единица на последния индекс (последната цифра)
////и ако стане 10 прибавяме едно наум към предишната и т.н.
//
////ако първата цифра ни е 9 и имаме едно наум, трябва да добавим единица в началото
////напр.: 99 + 1 = 100
//
//std::vector<int> plusOne(std::vector<int>& digits)
//{
//	std::vector<int> res(digits.size());
//	
//	int carry = 1;
//	for (int i = digits.size() - 1; i >= 0; i--)
//	{
//		int sum = digits[i] + carry;
//		if (sum == 10)
//		{
//			digits[i] = 0;
//			carry = 1;
//		}
//
//		else
//		{
//			digits[i] = sum;
//			carry = 0;
//		}
//
//		res[i] = digits[i];
//	}
//
//	if (res[0] == 0)
//	{
//		res.insert(res.begin(), 1);
//	}
//
//	return res;
//}