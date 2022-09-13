class Node :
	def __init__(self, coeff, power, next = None):
		self.coeff = coeff
		self.power = power
		self.next = next

def takeinput(arr):
	head = None
	for x in arr:

		head = Node(x[0], x[1], head)
		
	return head

def add(head1, head2):
	head = None
	while head1 and head2 :
		if head1.power == head2.power :
			coeffafteraddition = head1.coeff + head2.coeff
			head = Node(coeffafteraddition, head1.power, head)
			head1 = head1.next
			head2 = head2.next

		if head1.power < head2.power :
			head = Node(head1.coeff, head1.power, head)
			head1 = head1.next

		else :
			head = Node(head2.coeff, head2.power, head)
			head2 = head2.next

	while head1 :
		head = Node(head1.coeff, head1.power, head)
		head1 = head1.next

	while head2 :
		head = Node(head2.coeff, head2.power, head)
		head2 = head2.next

	return head 

def printpolynomial(head):
	ans = ""
	while head.next :
		ans += f"{head.coeff}x^{head.power} + "
		head = head.next

	ans += f"{head.coeff}x^{head.power}"

	print(ans)

arr1 = [[5, 3], [4, 2], [2, 0]]
arr2 = [[5, 1], [-5, 0]]
head1 = takeinput(arr1)
head2 = takeinput(arr2)
head = add(head1, head2)
printpolynomial(head)