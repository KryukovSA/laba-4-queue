#include <gtest.h>
#include "queue.h"

TEST(Queue, create_queue)
{
	ASSERT_NO_THROW(Queue<int> p(5));
}
TEST(Queue, can_add_in_full)
{
	ASSERT_ANY_THROW(Queue<int> p(MaxMemSize + 1));
}
TEST(Queue, get_next_elem_from_the_queue)
{
	Queue<int> p(10);
	EXPECT_EQ(p.GetNextIndex(1), 2);
}
TEST(Queue, put_elem)
{
	Queue<int> p(10);
	ASSERT_NO_THROW(p.Put(2));
}
TEST(Queue, can_get_elem)
{
	Queue<int> p(4);
	p.Put(2);
	ASSERT_NO_THROW(p.Get());
}
TEST(Queue, correcttly_get_elem_from_the_queue)
{
	Queue<int> p(10);
	p.Put(2);
	EXPECT_EQ(p.Get(), 2);
}
TEST(Queue, can_check_queue_is_empty)
{
	Queue<int> p(1);
	p.Put(1);//////////////
	EXPECT_EQ(p.IsEmpty(), 0);
	EXPECT_EQ(p.IsFull(), 1);
}
TEST(Queue, check_queue_is_full)
{
	Queue<int> p(2);
	p.Put(1);
	p.Put(2);
	EXPECT_EQ(p.IsFull(), 1);
}
TEST(Queue, cant_get_elem_from_empty_queue)
{
	Queue<int> p(2);
	p.Put(1);
	p.Get();
	ASSERT_ANY_THROW(p.Get());
}
TEST(Queue, not_put_elem_in_full_queue)
{
	Queue<int> p(3);
	p.Put(1);
	p.Put(2);
	p.Put(3);
	ASSERT_ANY_THROW(p.Put(4));
}
TEST(Queue, learn_the_first_element_queue)
{
	Queue<int> p(2);
	p.Put(4);
	EXPECT_EQ(p.Check(), 4);
}