#include <TQueue.h>
#include <gtest.h>


TEST(Memory_Tests, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue <int> q(5));
}

TEST(Memory_Tests, cant_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue <double> q(-2));
}

TEST(Memory_Tests, cant_create_queue_with_null_size)
{
	ASSERT_ANY_THROW(TQueue <int> q(0));
}

TEST(Memory_Tests, can_create_queue_with_default_size)
{
	ASSERT_NO_THROW(TQueue <int> q);
}

TEST(Memory_Tests, can_copy_queue)
{
	TQueue <int> q(4);

	ASSERT_NO_THROW(TQueue <int> q1(q));
}

TEST(Memory_Tests, corrert_copying_queue)
{
	TQueue <int> q(4);
	for (int i = 0; i < 4; i++)
		q.Push(i);
	TQueue <int> q1(q);

	EXPECT_EQ(q.Pop(), q1.Pop());
}

TEST(Memory_Tests, copied_queue_has_its_own_memory)
{
	TQueue <int> q(4);
	TQueue <int> q1(q);
	q.Push(5);
	q1.Push(4);

	EXPECT_NE(q.Pop(), q1.Pop());
}

TEST(TQueue, can_push_elem_to_not_full_queue)
{
	TQueue <int> q(4);

	ASSERT_NO_THROW(q.Push(5));
}

TEST(TQueue, cant_push_elem_to_full_queue)
{
	TQueue <int> q(4);
	for (int i = 0; i < 4; i++)
		q.Push(i);

	ASSERT_ANY_THROW(q.Push(4));
}

TEST(TQueue, can_show_front_value_from_not_empty_queue)
{
	TQueue <double> q(4);
	q.Push(4);
	q.Push(5);

	EXPECT_EQ(4, q.Front());
}

TEST(TQueue, can_show_back_value_from_not_empty_queue)
{
	TQueue <double> q(4);
	q.Push(4);
	q.Push(5);

	EXPECT_EQ(5, q.Back());
}

TEST(TQueue, cant_show_front_value_from_empty_queue)
{
	TQueue <int> q(5);

	ASSERT_ANY_THROW(q.Front());
}

TEST(TQueue, cant_show_back_value_from_empty_queue)
{
	TQueue <int> q(5);

	ASSERT_ANY_THROW(q.Back());
}

TEST(TQueue, can_get_value_from_not_empty_queue)
{
	TQueue <int> q(5);
	q.Push(4);
	q.Push(-7);

	EXPECT_EQ(4, q.Pop());
}

TEST(TQueue, cant_get_value_frow_empty_stack)
{
	TQueue <double> q(5);

	ASSERT_ANY_THROW(q.Pop());
}

TEST(TQueue, can_check_queue_on_empty)
{
	TQueue <int> q(5);
	q.Push(7);

	EXPECT_EQ(false, q.IsEmpty());
}

TEST(TQueue, can_check_empty_stack_on_empty)
{
	TQueue <int> q(5);

	EXPECT_EQ(true, q.IsEmpty());
}

TEST(TQueue, can_check_stack_on_full)
{
	TQueue <int> q(5);

	EXPECT_EQ(false, q.IsFull());
}

TEST(TQueue, can_check_full_stack_on_full)
{
	TQueue <int> q(5);
	for (int i = 0; i < 5; i++)
		q.Push(i);

	EXPECT_EQ(true, q.IsFull());
}

TEST(TQueue, can_clear_queue)
{
	TQueue <int> q(5);
	q.Push(7);
	q.Clear();

	EXPECT_EQ(true, q.IsEmpty());
}

TEST(TQueue, can_clear_empty_queue)
{
	TQueue <int> q(5);

	ASSERT_NO_THROW(q.Clear());
}