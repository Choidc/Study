#pragma once
#include"hash_map.h"

namespace ProCpp
{
	template <typename T>
	size_t hash<T>::operator()(const T& key) const
	{
		size_t bytes = sizeof (key);
		size_t res = 0;
		for (size_t i = 0; i < bytes; ++i)
		{
			unsigned char b = *((unsigned char*)&key + i);
			res += b;
		}
		return res;
	}

	size_t hash<std::string>::operator()(const std::string& key) const
	{
		size_t sum = 0;
		for (size_t i = 0; i < key.size (); ++i)
		{
			sum += (unsigned char)key[i];
		}
		return sum;
	}

#pragma region Const_Iterator
	template<typename HashMap>
	const_hash_map_iterator<HashMap>::const_hash_map_iterator ()
		: mBucketIndex (0), mListIterator (list_iterator_type ()), mHashmap (nullptr)
	{}

	template<typename HashMap>
	const_hash_map_iterator<HashMap>::const_hash_map_iterator (size_t bucket, list_iterator_type listIt, const HashMap* inHashmap)
		: mBucketIndex (bucket), mListIterator (listIt), mHashmap (inHashmap)
	{}

	template<typename HashMap>
	const typename const_hash_map_iterator<HashMap>::value_type& const_hash_map_iterator<HashMap>::operator*() const
	{
		return *mListIterator;
	}

	template<typename HashMap>
	const typename const_hash_map_iterator<HashMap>::value_type* const_hash_map_iterator<HashMap>::operator->() const
	{
		return &(*mListIterator);
	}

	template<typename HashMap>
	const_hash_map_iterator<HashMap>& const_hash_map_iterator<HashMap>::operator++()
	{
		increment ();
		return *this;
	}

	template<typename HashMap>
	const_hash_map_iterator<HashMap> const_hash_map_iterator<HashMap>::operator++(int)
	{
		auto oldIt = *this;
		increment ();
		return oldIt;
	}

	template<typename HashMap>
	const_hash_map_iterator<HashMap>& const_hash_map_iterator<HashMap>::operator--()
	{
		decrement ();
		return *this;
	}

	template<typename HashMap>
	const_hash_map_iterator<HashMap> const_hash_map_iterator<HashMap>::operator--(int)
	{
		auto oldIt = *this;
		decrement ();
		return oldIt;
	}

	template<typename HashMap>
	void const_hash_map_iterator<HashMap>::increment ()
	{
		++mListIterator;

		auto& buckets = mHashmap->mBuckets;
		if (mListIterator == std::end (buckets[mBucketIndex]))
		{
			for (size_t i = mBucketIndex + 1; i < buckets.size (); i++)
			{
				if (!buckets[i].empty ())
				{
					mListIterator = std::begin (buckets[i]);
					mBucketIndex = i;
					return;
				}
			}
			mBucketIndex = buckets.size () - 1;
			mListIterator = std::end (buckets[mBucketIndex]);
		}
	}

	template<typename HashMap>
	void const_hash_map_iterator<HashMap>::decrement ()
	{
		auto& buckets = mHashmap->mBuckets;
		if (mListIterator == std::begin (buckets[mBucketIndex]))
		{
			for (int i = mBucketIndex - 1; i >= 0; --i)
			{
				if (!buckets[i].empty ())
				{
					mListIterator = std::end (buckets[i]);
					--mListIterator;
					mBucketIndex = i;
					return;
				}
			}
			mBucketIndex = buckets.size () - 1;
			mListIterator = std::end (buckets[mBucketIndex]);
		}
		else
		{
			--mListIterator;
		}
	}

	template<typename HashMap>
	bool const_hash_map_iterator<HashMap>::operator==(const const_hash_map_iterator<HashMap>& rhs) const
	{
		return (mHashmap == rhs.mHashmap && mBucketIndex == rhs.mBucketIndex && mListIterator == rhs.mListIterator);
	}

	template<typename HashMap>
	bool const_hash_map_iterator<HashMap>::operator!=(const const_hash_map_iterator<HashMap>& rhs) const
	{
		return !(*this == rhs);
	}
#pragma endregion

#pragma region Iterator
	template<typename HashMap>
	typename hash_map_iterator<HashMap>::value_type& hash_map_iterator<HashMap>::operator*()
	{
		return const_cast<value_type&>(*this->mListIterator);
	}

	template<typename HashMap>
	typename hash_map_iterator<HashMap>::value_type* hash_map_iterator<HashMap>::operator->()
	{
		return const_cast<value_type*>(&(*this->mListIterator));
	}

	template<typename HashMap>
	hash_map_iterator<HashMap>& hash_map_iterator<HashMap>::operator++()
	{
		this->increment ();
		return *this;
	}

	template<typename HashMap>
	hash_map_iterator<HashMap> hash_map_iterator<HashMap>::operator++(int)
	{
		auto oldIt = *this;
		this->increment ();
		return oldIt;
	}

	template<typename HashMap>
	hash_map_iterator<HashMap>& hash_map_iterator<HashMap>::operator--()
	{
		this->decrement ();
		return *this;
	}

	template<typename HashMap>
	hash_map_iterator<HashMap> hash_map_iterator<HashMap>::operator--(int)
	{
		auto oldIt = *this;
		this->decrement ();
		return oldIt;
	}

#pragma endregion


#pragma region Iterator_Method
	template <typename Key, typename T, typename Compare, typename Hash>
	typename hash_map<Key, T, Compare, Hash>::iterator hash_map<Key, T, Compare, Hash>::begin ()
	{
		if (mSize == 0)
		{
			return end ();
		}

		for (size_t i = 0; i < mBuckets.size (); ++i)
		{
			if (!mBuckets[i].empty ())
			{
				return hash_map_iterator<hash_map_type> (i, std::begin (mBuckets[i]), this);
			}
		}
		return end ();
	}

	template <typename Key, typename T, typename Compare, typename Hash>
	typename hash_map<Key, T, Compare, Hash>::const_iterator hash_map<Key, T, Compare, Hash>::begin () const
	{
		return const_cast<hash_map_type*>(this)->begin ();
	}

	template <typename Key, typename T, typename Compare, typename Hash>
	typename hash_map<Key, T, Compare, Hash>::const_iterator hash_map<Key, T, Compare, Hash>::cbegin () const
	{
		return begin ();
	}

	template <typename Key, typename T, typename Compare, typename Hash>
	typename hash_map<Key, T, Compare, Hash>::iterator hash_map<Key, T, Compare, Hash>::end ()
	{
		size_t bucket = mBuckets.size () - 1;
		return hash_map_iterator<hash_map_type> (bucket, std::end (mBuckets[bucket]), this);
	}

	template <typename Key, typename T, typename Compare, typename Hash>
	typename hash_map<Key, T, Compare, Hash>::const_iterator hash_map<Key, T, Compare, Hash>::end () const
	{
		return const_cast<hash_map_type*>(this)->end ();
	}

	template <typename Key, typename T, typename Compare, typename Hash>
	typename hash_map<Key, T, Compare, Hash>::const_iterator hash_map<Key, T, Compare, Hash>::cend () const
	{
		return end ();
	}
#pragma endregion

	template <typename Key, typename T, typename Compare, typename Hash>
	hash_map<Key, T, Compare, Hash>::~hash_map () {}

	template <typename Key, typename T, typename Compare, typename Hash>
	hash_map<Key, T, Compare, Hash>::hash_map (const Compare& comp, size_t numBuckets, const Hash& hash)
		: mSize (0), mComp (comp), mHash (hash)
	{
		if (numBuckets == 0)
		{
			throw std::invalid_argument ("Number of buckets must be positive");
		}
		mBuckets.resize (numBuckets);
	}

	#pragma region Find

	template <typename Key, typename T, typename Compare, typename Hash>
	typename hash_map<Key, T, Compare, Hash>::ListType::iterator hash_map<Key, T, Compare, Hash>::findElement (const key_type& k, size_t& bucket)
	{
		bucket = mHash (k) % mBuckets.size ();

		for (auto it = std::begin (mBuckets[bucket]); it != std::end (mBuckets[bucket]); ++it)
		{
			if (mComp (it->first, k))
			{
				return it;
			}
		}
		return std::end (mBuckets[bucket]);
	}

	template <typename Key, typename T, typename Compare, typename Hash>
	typename hash_map<Key, T, Compare, Hash>::value_type* hash_map<Key, T, Compare, Hash>::find (const key_type& k)
	{
		size_t bucket;

		auto it = findElement (k, bucket);
		if (it == std::end (mBuckets[bucket]))
		{
			return nullptr;
		}
		return &(*it);
	}

	template <typename Key, typename T, typename Compare, typename Hash>
	const typename hash_map<Key, T, Compare, Hash>::value_type* hash_map<Key, T, Compare, Hash>::find (const key_type& k) const
	{
		return const_cast<hash_map<Key, T, Compare, Hash>*>(this)->find (k);
	}

	template <typename Key, typename T, typename Compare, typename Hash>
	T& hash_map<Key, T, Compare, Hash>::operator[] (const key_type& k)
	{
		// Try to find the element. If it doesn't exist, add a new element.
		value_type* found = find (k);
		if (found == nullptr)
		{
			insert (std::make_pair (k, T ()));
			found = find (k);
		}
		return found->second;
	}

	#pragma endregion

	#pragma region Insert
	template <typename Key, typename T, typename Compare, typename Hash>
	void hash_map<Key, T, Compare, Hash>::insert (const value_type& x)
	{
		size_t bucket;

		auto it = findElement (x.first, bucket);

		if (it != std::end (mBuckets[bucket]))
		{
			return;
		}
		else
		{
			mSize++;
			mBuckets[bucket].push_back (x);
		}
	}
	#pragma endregion

	#pragma region erase
	template <typename Key, typename T, typename Compare, typename Hash>
	void hash_map<Key, T, Compare, Hash>::erase (const key_type& k)
	{
		size_t bucket;

		auto it = findElement (k, bucket);

		if (it != std::end (mBuckets[bucket]))
		{
			mBuckets[bucket].erase (it);
			mSize--;
		}
	}
	#pragma endregion

}