#include <iostream>
#include <vector>
#include <string>
#include <memory>

struct Block
{
    int id;
    int start;
    int length;
};

struct C7B
{
    int m;
    int max_id;
    std::vector<Block> blocks;
};

static void Alloc(C7B *h, int n)
{
    for (size_t idx = 1; idx < h->blocks.size(); ++idx)
    {
        if (h->blocks[idx].start - (h->blocks[idx - 1].start + h->blocks[idx - 1].length) >= n)
        {
            ++h->max_id;
            Block block;
            block.id = h->max_id;
            block.start = h->blocks[idx - 1].start + h->blocks[idx - 1].length;
            block.length = n;
            h->blocks.insert(h->blocks.begin() + idx, block);
            std::cout << h->max_id << std::endl;
            return;
        }
    }

    std::cout << "NULL" << std::endl;
}

static void Erase(C7B *h, int x)
{
    if (x <= 0)
    {
        std::cout << "ILLEGAL_ERASE_ARGUMENT" << std::endl;
        return;
    }

    for (size_t idx = 0; idx < h->blocks.size(); ++idx)
    {
        if (h->blocks[idx].id == x)
        {
            h->blocks.erase(h->blocks.begin() + idx);
            return;
        }
    }

    std::cout << "ILLEGAL_ERASE_ARGUMENT" << std::endl;
}

static void Defragment(C7B *h)
{
    for (size_t idx = 1; idx < h->blocks.size() - 1; ++idx)
    {
        if (h->blocks[idx].start > h->blocks[idx - 1].start + h->blocks[idx - 1].length)
        {
            h->blocks[idx].start = h->blocks[idx - 1].start + h->blocks[idx - 1].length;
        }
    }
}

int main(int argc, char **argv)
{
    std::shared_ptr<C7B> h = std::make_shared<C7B>();
    int t;
    std::cin >> t >> h->m;
    // 添加起始块
    {
        Block block;
        block.id = 0;
        block.start = 0;
        block.length = 0;
        h->blocks.push_back(block);
    }

    // 添加结束块
    {
        Block block;
        block.id = 0;
        block.start = h->m;
        block.length = 0;
        h->blocks.push_back(block);
    }

    for (int step = 0; step < t; ++step)
    {
        std::string cmd;
        std::cin >> cmd;

        if ("alloc" == cmd)
        {
            int n;
            std::cin >> n;
            Alloc(h.get(), n);
        }
        else if ("erase" == cmd)
        {
            int x;
            std::cin >> x;
            Erase(h.get(), x);
        }
        else if ("defragment" == cmd)
        {
            Defragment(h.get());
        }
    }

    return 0;
}
