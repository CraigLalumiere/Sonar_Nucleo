// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ConfigPlot.proto

#include "ConfigPlot.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
class ConfigPlotDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ConfigPlot> _instance;
} _ConfigPlot_default_instance_;
static void InitDefaultsscc_info_ConfigPlot_ConfigPlot_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_ConfigPlot_default_instance_;
    new (ptr) ::ConfigPlot();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::ConfigPlot::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ConfigPlot_ConfigPlot_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_ConfigPlot_ConfigPlot_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_ConfigPlot_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_ConfigPlot_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_ConfigPlot_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_ConfigPlot_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::ConfigPlot, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::ConfigPlot, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::ConfigPlot, plot_number_),
  PROTOBUF_FIELD_OFFSET(::ConfigPlot, plot_title_),
  PROTOBUF_FIELD_OFFSET(::ConfigPlot, x_label_),
  PROTOBUF_FIELD_OFFSET(::ConfigPlot, x_units_),
  PROTOBUF_FIELD_OFFSET(::ConfigPlot, y_label_),
  PROTOBUF_FIELD_OFFSET(::ConfigPlot, y_units_),
  5,
  0,
  1,
  2,
  3,
  4,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 11, sizeof(::ConfigPlot)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_ConfigPlot_default_instance_),
};

const char descriptor_table_protodef_ConfigPlot_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\020ConfigPlot.proto\"y\n\nConfigPlot\022\023\n\013plot"
  "_number\030\001 \002(\r\022\022\n\nplot_title\030\002 \002(\t\022\017\n\007x_l"
  "abel\030\003 \002(\t\022\017\n\007x_units\030\004 \002(\t\022\017\n\007y_label\030\005"
  " \002(\t\022\017\n\007y_units\030\006 \002(\t"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_ConfigPlot_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_ConfigPlot_2eproto_sccs[1] = {
  &scc_info_ConfigPlot_ConfigPlot_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_ConfigPlot_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_ConfigPlot_2eproto = {
  false, false, descriptor_table_protodef_ConfigPlot_2eproto, "ConfigPlot.proto", 141,
  &descriptor_table_ConfigPlot_2eproto_once, descriptor_table_ConfigPlot_2eproto_sccs, descriptor_table_ConfigPlot_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_ConfigPlot_2eproto::offsets,
  file_level_metadata_ConfigPlot_2eproto, 1, file_level_enum_descriptors_ConfigPlot_2eproto, file_level_service_descriptors_ConfigPlot_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_ConfigPlot_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_ConfigPlot_2eproto)), true);

// ===================================================================

void ConfigPlot::InitAsDefaultInstance() {
}
class ConfigPlot::_Internal {
 public:
  using HasBits = decltype(std::declval<ConfigPlot>()._has_bits_);
  static void set_has_plot_number(HasBits* has_bits) {
    (*has_bits)[0] |= 32u;
  }
  static void set_has_plot_title(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_x_label(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_x_units(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_y_label(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_y_units(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static bool MissingRequiredFields(const HasBits& has_bits) {
    return ((has_bits[0] & 0x0000003f) ^ 0x0000003f) != 0;
  }
};

ConfigPlot::ConfigPlot(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:ConfigPlot)
}
ConfigPlot::ConfigPlot(const ConfigPlot& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  plot_title_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_plot_title()) {
    plot_title_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_plot_title(),
      GetArena());
  }
  x_label_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_x_label()) {
    x_label_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_x_label(),
      GetArena());
  }
  x_units_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_x_units()) {
    x_units_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_x_units(),
      GetArena());
  }
  y_label_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_y_label()) {
    y_label_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_y_label(),
      GetArena());
  }
  y_units_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_y_units()) {
    y_units_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_y_units(),
      GetArena());
  }
  plot_number_ = from.plot_number_;
  // @@protoc_insertion_point(copy_constructor:ConfigPlot)
}

void ConfigPlot::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ConfigPlot_ConfigPlot_2eproto.base);
  plot_title_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  x_label_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  x_units_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  y_label_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  y_units_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  plot_number_ = 0u;
}

ConfigPlot::~ConfigPlot() {
  // @@protoc_insertion_point(destructor:ConfigPlot)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void ConfigPlot::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  plot_title_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  x_label_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  x_units_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  y_label_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  y_units_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void ConfigPlot::ArenaDtor(void* object) {
  ConfigPlot* _this = reinterpret_cast< ConfigPlot* >(object);
  (void)_this;
}
void ConfigPlot::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void ConfigPlot::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ConfigPlot& ConfigPlot::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ConfigPlot_ConfigPlot_2eproto.base);
  return *internal_default_instance();
}


void ConfigPlot::Clear() {
// @@protoc_insertion_point(message_clear_start:ConfigPlot)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    if (cached_has_bits & 0x00000001u) {
      plot_title_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000002u) {
      x_label_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000004u) {
      x_units_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000008u) {
      y_label_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000010u) {
      y_units_.ClearNonDefaultToEmpty();
    }
  }
  plot_number_ = 0u;
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ConfigPlot::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required uint32 plot_number = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_plot_number(&has_bits);
          plot_number_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required string plot_title = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_plot_title();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ConfigPlot.plot_title");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required string x_label = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_x_label();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ConfigPlot.x_label");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required string x_units = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          auto str = _internal_mutable_x_units();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ConfigPlot.x_units");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required string y_label = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          auto str = _internal_mutable_y_label();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ConfigPlot.y_label");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required string y_units = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 50)) {
          auto str = _internal_mutable_y_units();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ConfigPlot.y_units");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* ConfigPlot::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ConfigPlot)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required uint32 plot_number = 1;
  if (cached_has_bits & 0x00000020u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_plot_number(), target);
  }

  // required string plot_title = 2;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_plot_title().data(), static_cast<int>(this->_internal_plot_title().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "ConfigPlot.plot_title");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_plot_title(), target);
  }

  // required string x_label = 3;
  if (cached_has_bits & 0x00000002u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_x_label().data(), static_cast<int>(this->_internal_x_label().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "ConfigPlot.x_label");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_x_label(), target);
  }

  // required string x_units = 4;
  if (cached_has_bits & 0x00000004u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_x_units().data(), static_cast<int>(this->_internal_x_units().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "ConfigPlot.x_units");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_x_units(), target);
  }

  // required string y_label = 5;
  if (cached_has_bits & 0x00000008u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_y_label().data(), static_cast<int>(this->_internal_y_label().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "ConfigPlot.y_label");
    target = stream->WriteStringMaybeAliased(
        5, this->_internal_y_label(), target);
  }

  // required string y_units = 6;
  if (cached_has_bits & 0x00000010u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_y_units().data(), static_cast<int>(this->_internal_y_units().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "ConfigPlot.y_units");
    target = stream->WriteStringMaybeAliased(
        6, this->_internal_y_units(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ConfigPlot)
  return target;
}

size_t ConfigPlot::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:ConfigPlot)
  size_t total_size = 0;

  if (_internal_has_plot_title()) {
    // required string plot_title = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_plot_title());
  }

  if (_internal_has_x_label()) {
    // required string x_label = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_x_label());
  }

  if (_internal_has_x_units()) {
    // required string x_units = 4;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_x_units());
  }

  if (_internal_has_y_label()) {
    // required string y_label = 5;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_y_label());
  }

  if (_internal_has_y_units()) {
    // required string y_units = 6;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_y_units());
  }

  if (_internal_has_plot_number()) {
    // required uint32 plot_number = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_plot_number());
  }

  return total_size;
}
size_t ConfigPlot::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ConfigPlot)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x0000003f) ^ 0x0000003f) == 0) {  // All required fields are present.
    // required string plot_title = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_plot_title());

    // required string x_label = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_x_label());

    // required string x_units = 4;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_x_units());

    // required string y_label = 5;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_y_label());

    // required string y_units = 6;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_y_units());

    // required uint32 plot_number = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_plot_number());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ConfigPlot::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ConfigPlot)
  GOOGLE_DCHECK_NE(&from, this);
  const ConfigPlot* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<ConfigPlot>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ConfigPlot)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ConfigPlot)
    MergeFrom(*source);
  }
}

void ConfigPlot::MergeFrom(const ConfigPlot& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ConfigPlot)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000003fu) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_plot_title(from._internal_plot_title());
    }
    if (cached_has_bits & 0x00000002u) {
      _internal_set_x_label(from._internal_x_label());
    }
    if (cached_has_bits & 0x00000004u) {
      _internal_set_x_units(from._internal_x_units());
    }
    if (cached_has_bits & 0x00000008u) {
      _internal_set_y_label(from._internal_y_label());
    }
    if (cached_has_bits & 0x00000010u) {
      _internal_set_y_units(from._internal_y_units());
    }
    if (cached_has_bits & 0x00000020u) {
      plot_number_ = from.plot_number_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void ConfigPlot::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ConfigPlot)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ConfigPlot::CopyFrom(const ConfigPlot& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ConfigPlot)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ConfigPlot::IsInitialized() const {
  if (_Internal::MissingRequiredFields(_has_bits_)) return false;
  return true;
}

void ConfigPlot::InternalSwap(ConfigPlot* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  plot_title_.Swap(&other->plot_title_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  x_label_.Swap(&other->x_label_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  x_units_.Swap(&other->x_units_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  y_label_.Swap(&other->y_label_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  y_units_.Swap(&other->y_units_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  swap(plot_number_, other->plot_number_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ConfigPlot::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::ConfigPlot* Arena::CreateMaybeMessage< ::ConfigPlot >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ConfigPlot >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
