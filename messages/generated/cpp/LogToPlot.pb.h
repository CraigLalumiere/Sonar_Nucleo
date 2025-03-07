// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: LogToPlot.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_LogToPlot_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_LogToPlot_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3012000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3012004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_LogToPlot_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_LogToPlot_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_LogToPlot_2eproto;
class LogToPlot;
class LogToPlotDefaultTypeInternal;
extern LogToPlotDefaultTypeInternal _LogToPlot_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::LogToPlot* Arena::CreateMaybeMessage<::LogToPlot>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class LogToPlot PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:LogToPlot) */ {
 public:
  inline LogToPlot() : LogToPlot(nullptr) {};
  virtual ~LogToPlot();

  LogToPlot(const LogToPlot& from);
  LogToPlot(LogToPlot&& from) noexcept
    : LogToPlot() {
    *this = ::std::move(from);
  }

  inline LogToPlot& operator=(const LogToPlot& from) {
    CopyFrom(from);
    return *this;
  }
  inline LogToPlot& operator=(LogToPlot&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const LogToPlot& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const LogToPlot* internal_default_instance() {
    return reinterpret_cast<const LogToPlot*>(
               &_LogToPlot_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(LogToPlot& a, LogToPlot& b) {
    a.Swap(&b);
  }
  inline void Swap(LogToPlot* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(LogToPlot* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline LogToPlot* New() const final {
    return CreateMaybeMessage<LogToPlot>(nullptr);
  }

  LogToPlot* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<LogToPlot>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const LogToPlot& from);
  void MergeFrom(const LogToPlot& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(LogToPlot* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "LogToPlot";
  }
  protected:
  explicit LogToPlot(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_LogToPlot_2eproto);
    return ::descriptor_table_LogToPlot_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kDataLabelFieldNumber = 2,
    kPlotNumberFieldNumber = 1,
    kMillisecondsTickFieldNumber = 3,
    kDataYFieldNumber = 4,
  };
  // required string data_label = 2;
  bool has_data_label() const;
  private:
  bool _internal_has_data_label() const;
  public:
  void clear_data_label();
  const std::string& data_label() const;
  void set_data_label(const std::string& value);
  void set_data_label(std::string&& value);
  void set_data_label(const char* value);
  void set_data_label(const char* value, size_t size);
  std::string* mutable_data_label();
  std::string* release_data_label();
  void set_allocated_data_label(std::string* data_label);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_data_label();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_data_label(
      std::string* data_label);
  private:
  const std::string& _internal_data_label() const;
  void _internal_set_data_label(const std::string& value);
  std::string* _internal_mutable_data_label();
  public:

  // required uint32 plot_number = 1;
  bool has_plot_number() const;
  private:
  bool _internal_has_plot_number() const;
  public:
  void clear_plot_number();
  ::PROTOBUF_NAMESPACE_ID::uint32 plot_number() const;
  void set_plot_number(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_plot_number() const;
  void _internal_set_plot_number(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // required uint32 milliseconds_tick = 3;
  bool has_milliseconds_tick() const;
  private:
  bool _internal_has_milliseconds_tick() const;
  public:
  void clear_milliseconds_tick();
  ::PROTOBUF_NAMESPACE_ID::uint32 milliseconds_tick() const;
  void set_milliseconds_tick(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_milliseconds_tick() const;
  void _internal_set_milliseconds_tick(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // required float data_y = 4;
  bool has_data_y() const;
  private:
  bool _internal_has_data_y() const;
  public:
  void clear_data_y();
  float data_y() const;
  void set_data_y(float value);
  private:
  float _internal_data_y() const;
  void _internal_set_data_y(float value);
  public:

  // @@protoc_insertion_point(class_scope:LogToPlot)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr data_label_;
  ::PROTOBUF_NAMESPACE_ID::uint32 plot_number_;
  ::PROTOBUF_NAMESPACE_ID::uint32 milliseconds_tick_;
  float data_y_;
  friend struct ::TableStruct_LogToPlot_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// LogToPlot

// required uint32 plot_number = 1;
inline bool LogToPlot::_internal_has_plot_number() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool LogToPlot::has_plot_number() const {
  return _internal_has_plot_number();
}
inline void LogToPlot::clear_plot_number() {
  plot_number_ = 0u;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 LogToPlot::_internal_plot_number() const {
  return plot_number_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 LogToPlot::plot_number() const {
  // @@protoc_insertion_point(field_get:LogToPlot.plot_number)
  return _internal_plot_number();
}
inline void LogToPlot::_internal_set_plot_number(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000002u;
  plot_number_ = value;
}
inline void LogToPlot::set_plot_number(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_plot_number(value);
  // @@protoc_insertion_point(field_set:LogToPlot.plot_number)
}

// required string data_label = 2;
inline bool LogToPlot::_internal_has_data_label() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool LogToPlot::has_data_label() const {
  return _internal_has_data_label();
}
inline void LogToPlot::clear_data_label() {
  data_label_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& LogToPlot::data_label() const {
  // @@protoc_insertion_point(field_get:LogToPlot.data_label)
  return _internal_data_label();
}
inline void LogToPlot::set_data_label(const std::string& value) {
  _internal_set_data_label(value);
  // @@protoc_insertion_point(field_set:LogToPlot.data_label)
}
inline std::string* LogToPlot::mutable_data_label() {
  // @@protoc_insertion_point(field_mutable:LogToPlot.data_label)
  return _internal_mutable_data_label();
}
inline const std::string& LogToPlot::_internal_data_label() const {
  return data_label_.Get();
}
inline void LogToPlot::_internal_set_data_label(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  data_label_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void LogToPlot::set_data_label(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  data_label_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:LogToPlot.data_label)
}
inline void LogToPlot::set_data_label(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  data_label_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:LogToPlot.data_label)
}
inline void LogToPlot::set_data_label(const char* value,
    size_t size) {
  _has_bits_[0] |= 0x00000001u;
  data_label_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:LogToPlot.data_label)
}
inline std::string* LogToPlot::_internal_mutable_data_label() {
  _has_bits_[0] |= 0x00000001u;
  return data_label_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* LogToPlot::release_data_label() {
  // @@protoc_insertion_point(field_release:LogToPlot.data_label)
  if (!_internal_has_data_label()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return data_label_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void LogToPlot::set_allocated_data_label(std::string* data_label) {
  if (data_label != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  data_label_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), data_label,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:LogToPlot.data_label)
}
inline std::string* LogToPlot::unsafe_arena_release_data_label() {
  // @@protoc_insertion_point(field_unsafe_arena_release:LogToPlot.data_label)
  GOOGLE_DCHECK(GetArena() != nullptr);
  _has_bits_[0] &= ~0x00000001u;
  return data_label_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void LogToPlot::unsafe_arena_set_allocated_data_label(
    std::string* data_label) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (data_label != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  data_label_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      data_label, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:LogToPlot.data_label)
}

// required uint32 milliseconds_tick = 3;
inline bool LogToPlot::_internal_has_milliseconds_tick() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool LogToPlot::has_milliseconds_tick() const {
  return _internal_has_milliseconds_tick();
}
inline void LogToPlot::clear_milliseconds_tick() {
  milliseconds_tick_ = 0u;
  _has_bits_[0] &= ~0x00000004u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 LogToPlot::_internal_milliseconds_tick() const {
  return milliseconds_tick_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 LogToPlot::milliseconds_tick() const {
  // @@protoc_insertion_point(field_get:LogToPlot.milliseconds_tick)
  return _internal_milliseconds_tick();
}
inline void LogToPlot::_internal_set_milliseconds_tick(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000004u;
  milliseconds_tick_ = value;
}
inline void LogToPlot::set_milliseconds_tick(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_milliseconds_tick(value);
  // @@protoc_insertion_point(field_set:LogToPlot.milliseconds_tick)
}

// required float data_y = 4;
inline bool LogToPlot::_internal_has_data_y() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool LogToPlot::has_data_y() const {
  return _internal_has_data_y();
}
inline void LogToPlot::clear_data_y() {
  data_y_ = 0;
  _has_bits_[0] &= ~0x00000008u;
}
inline float LogToPlot::_internal_data_y() const {
  return data_y_;
}
inline float LogToPlot::data_y() const {
  // @@protoc_insertion_point(field_get:LogToPlot.data_y)
  return _internal_data_y();
}
inline void LogToPlot::_internal_set_data_y(float value) {
  _has_bits_[0] |= 0x00000008u;
  data_y_ = value;
}
inline void LogToPlot::set_data_y(float value) {
  _internal_set_data_y(value);
  // @@protoc_insertion_point(field_set:LogToPlot.data_y)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_LogToPlot_2eproto
