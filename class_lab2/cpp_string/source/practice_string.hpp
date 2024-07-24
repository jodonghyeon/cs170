#pragma once

namespace CS170
{
    class [[nodiscard]] practice_string
    {
    public:
        using size_type       = int;
        using reference       = char&;
        using const_reference = const char&;
        using pointer         = char*;
        using const_pointer   = const char*;

    public:
        practice_string() noexcept;
        practice_string(const_pointer cstring);
        practice_string(const practice_string& other) noexcept;
        ~practice_string();

        practice_string& operator=(const practice_string& other) noexcept;
        practice_string& operator=(const_pointer cstring) noexcept;

        [[nodiscard]] const_reference operator[](size_type index) const;
        [[nodiscard]] reference       operator[](size_type index);
        [[nodiscard]] const_pointer   as_c_string() const noexcept;
        explicit                      operator const_pointer() const;

        [[nodiscard]] bool      is_empty() const noexcept;
        [[nodiscard]] size_type length() const noexcept;

        practice_string& operator+=(const practice_string& other) noexcept;
        practice_string& operator+=(const_pointer cstring) noexcept;
        bool             operator==(const_pointer cstring) const noexcept;

    private:
        int const_string_length(const_pointer cstring)const;
        int string_length(const pointer cstring)const;
        void const_string_copy(pointer cstring, const_pointer string);
        practice_string& adding(const practice_string& other);
        
    private:
        pointer string=nullptr;
        size_type length;
    };


    practice_string operator+(const practice_string& left, const practice_string& right) noexcept;

    practice_string operator+(const practice_string& left, practice_string::const_pointer right_cstring) noexcept;

    practice_string operator+(practice_string::const_pointer left_cstring, const practice_string& right) noexcept;

    bool operator==(const practice_string& left, const practice_string& right) noexcept;

    bool operator==(practice_string::const_pointer cstring, const practice_string& string) noexcept;

    bool operator!=(const practice_string& left, const practice_string& right) noexcept;

    bool operator!=(practice_string::const_pointer cstring, const practice_string& string) noexcept;

    bool operator!=(const practice_string& string, practice_string::const_pointer cstring) noexcept;
}
